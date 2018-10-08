/**
 * S.I.M.P.L.E. - Smart Intuitive Messaging Platform with Less Effort
 * Copyright (C) 2018 Salvatore Virga - salvo.virga@tum.de, Fernanda Levy
 * Langsch - fernanda.langsch@tum.de
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef SIMPLE_MSGS_POINT_STAMPED_H
#define SIMPLE_MSGS_POINT_STAMPED_H

#include <mutex>
#include <ostream>

#include "generated/point_stamped_generated.h"
#include "generic_message.h"
#include "header.h"
#include "point.h"

namespace simple_msgs {
/**
 * @class PointStamped point_stamped.h.
 * @brief Thread-safe wrapper for a Flatbuffers PointStamped message.
 * It contains a Point and a Header message.
 */
class PointStamped : public GenericMessage {
public:
  PointStamped() = default;

  /**
   * @brief Construct a PointStamped message given its Header and Point.
   */
  PointStamped(const Header&, const Point&);

  /**
   * @brief Construct a PointStamped message given its Header and Point.
   */
  PointStamped(Header&&, Point&&);

  /**
   * @brief Construct a PointStamped message using a raw memory coming from network.
   */
  PointStamped(const void*);

  /**
   * @brief Copy constructor.
   */
  PointStamped(const PointStamped&);

  /**
   * @brief Move constructor.
   */
  PointStamped(PointStamped&&) noexcept;

  /**
   * @brief Copy assignment operator.
   */
  PointStamped& operator=(const PointStamped&);

  /**
   * @brief Move assignment operator.
   */
  PointStamped& operator=(PointStamped&&) noexcept;

  /**
   * @brief Copy assignment operator that uses raw memory coming from the network.
   */
  PointStamped& operator=(std::shared_ptr<void*>);

  /**
   * @brief Returns true if lhs is equal to rhs, false otherwise.
   */
  inline bool operator==(const PointStamped& rhs) const {
    std::lock(mutex_, rhs.mutex_);
    std::lock_guard<std::mutex> lock{mutex_, std::adopt_lock};
    std::lock_guard<std::mutex> other_lock{rhs.mutex_, std::adopt_lock};
    return (point_ == rhs.point_ && header_ == rhs.header_);
  }

  /**
   * @brief Returns true if lhs is not equal to rhs, false otherwise.
   */
  inline bool operator!=(const PointStamped& rhs) const { return !(*this == rhs); }

  /**
   * @brief Stream extraction operator.
   */
  friend std::ostream& operator<<(std::ostream&, const PointStamped&);

  /**
   * @brief Builds and returns the buffer accordingly to the values currently stored.
   */
  std::shared_ptr<flatbuffers::DetachedBuffer> getBufferData() const override;

  /**
   * @brief Returns the message Header.
   */
  inline Header& getHeader() {
    std::lock_guard<std::mutex> lock{mutex_};
    return header_;
  }

  /**
   * @brief Returns the message Header.
   */
  inline const Header& getHeader() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return header_;
  }

  /**
   * @brief Returns the message Point.
   */
  inline Point& getPoint() {
    std::lock_guard<std::mutex> lock{mutex_};
    return point_;
  }

  /**
   * @brief Returns the message Point.
   */
  inline const Point& getPoint() const {
    std::lock_guard<std::mutex> lock{mutex_};
    return point_;
  }

  /**
   * @brief Modifies the message header.
   */
  void setHeader(const Header&);
  /**
   * @brief Modifies the message point.
   */

  void setPoint(const Point&);
  /**
   * @brief Returns an identifier of the message type generated by the flatbuffers.
   */
  static inline std::string getTopic() { return PointStampedFbsIdentifier(); }

private:
  //! Thread safe copy and move constructors.
  PointStamped(const PointStamped& other, const std::lock_guard<std::mutex>&);
  PointStamped(PointStamped&& other, const std::lock_guard<std::mutex>&) noexcept;

  mutable std::mutex mutex_{};
  Header header_{};
  Point point_{};
};
}  // Namespace simple_msgs.

#endif  // SIMPLE_MSGS_POINT_STAMPED_H