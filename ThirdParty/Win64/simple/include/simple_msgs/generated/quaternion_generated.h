// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_QUATERNION_SIMPLE_MSGS_H_
#define FLATBUFFERS_GENERATED_QUATERNION_SIMPLE_MSGS_H_

#include "flatbuffers/flatbuffers.h"

namespace simple_msgs {

struct QuaternionFbs;

struct QuaternionFbs FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_X = 4,
    VT_Y = 6,
    VT_Z = 8,
    VT_W = 10
  };
  double x() const {
    return GetField<double>(VT_X, 0.0);
  }
  double y() const {
    return GetField<double>(VT_Y, 0.0);
  }
  double z() const {
    return GetField<double>(VT_Z, 0.0);
  }
  double w() const {
    return GetField<double>(VT_W, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_X) &&
           VerifyField<double>(verifier, VT_Y) &&
           VerifyField<double>(verifier, VT_Z) &&
           VerifyField<double>(verifier, VT_W) &&
           verifier.EndTable();
  }
};

struct QuaternionFbsBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_x(double x) {
    fbb_.AddElement<double>(QuaternionFbs::VT_X, x, 0.0);
  }
  void add_y(double y) {
    fbb_.AddElement<double>(QuaternionFbs::VT_Y, y, 0.0);
  }
  void add_z(double z) {
    fbb_.AddElement<double>(QuaternionFbs::VT_Z, z, 0.0);
  }
  void add_w(double w) {
    fbb_.AddElement<double>(QuaternionFbs::VT_W, w, 0.0);
  }
  explicit QuaternionFbsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  QuaternionFbsBuilder &operator=(const QuaternionFbsBuilder &);
  flatbuffers::Offset<QuaternionFbs> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<QuaternionFbs>(end);
    return o;
  }
};

inline flatbuffers::Offset<QuaternionFbs> CreateQuaternionFbs(
    flatbuffers::FlatBufferBuilder &_fbb,
    double x = 0.0,
    double y = 0.0,
    double z = 0.0,
    double w = 0.0) {
  QuaternionFbsBuilder builder_(_fbb);
  builder_.add_w(w);
  builder_.add_z(z);
  builder_.add_y(y);
  builder_.add_x(x);
  return builder_.Finish();
}

inline const simple_msgs::QuaternionFbs *GetQuaternionFbs(const void *buf) {
  return flatbuffers::GetRoot<simple_msgs::QuaternionFbs>(buf);
}

inline const simple_msgs::QuaternionFbs *GetSizePrefixedQuaternionFbs(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<simple_msgs::QuaternionFbs>(buf);
}

inline const char *QuaternionFbsIdentifier() {
  return "QUAT";
}

inline bool QuaternionFbsBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, QuaternionFbsIdentifier());
}

inline bool VerifyQuaternionFbsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<simple_msgs::QuaternionFbs>(QuaternionFbsIdentifier());
}

inline bool VerifySizePrefixedQuaternionFbsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<simple_msgs::QuaternionFbs>(QuaternionFbsIdentifier());
}

inline void FinishQuaternionFbsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<simple_msgs::QuaternionFbs> root) {
  fbb.Finish(root, QuaternionFbsIdentifier());
}

inline void FinishSizePrefixedQuaternionFbsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<simple_msgs::QuaternionFbs> root) {
  fbb.FinishSizePrefixed(root, QuaternionFbsIdentifier());
}

}  // namespace simple_msgs

#endif  // FLATBUFFERS_GENERATED_QUATERNION_SIMPLE_MSGS_H_
