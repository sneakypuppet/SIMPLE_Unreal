// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_POSESTAMPED_SIMPLE_MSGS_H_
#define FLATBUFFERS_GENERATED_POSESTAMPED_SIMPLE_MSGS_H_

#include "flatbuffers/flatbuffers.h"

namespace simple_msgs {

struct PoseStampedFbs;

struct PoseStampedFbs FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_POSE = 4,
    VT_HEADER = 6
  };
  const flatbuffers::Vector<uint8_t> *pose() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_POSE);
  }
  const flatbuffers::Vector<uint8_t> *header() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_HEADER);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POSE) &&
           verifier.VerifyVector(pose()) &&
           VerifyOffset(verifier, VT_HEADER) &&
           verifier.VerifyVector(header()) &&
           verifier.EndTable();
  }
};

struct PoseStampedFbsBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pose(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> pose) {
    fbb_.AddOffset(PoseStampedFbs::VT_POSE, pose);
  }
  void add_header(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> header) {
    fbb_.AddOffset(PoseStampedFbs::VT_HEADER, header);
  }
  explicit PoseStampedFbsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PoseStampedFbsBuilder &operator=(const PoseStampedFbsBuilder &);
  flatbuffers::Offset<PoseStampedFbs> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PoseStampedFbs>(end);
    return o;
  }
};

inline flatbuffers::Offset<PoseStampedFbs> CreatePoseStampedFbs(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> pose = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> header = 0) {
  PoseStampedFbsBuilder builder_(_fbb);
  builder_.add_header(header);
  builder_.add_pose(pose);
  return builder_.Finish();
}

inline flatbuffers::Offset<PoseStampedFbs> CreatePoseStampedFbsDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *pose = nullptr,
    const std::vector<uint8_t> *header = nullptr) {
  return simple_msgs::CreatePoseStampedFbs(
      _fbb,
      pose ? _fbb.CreateVector<uint8_t>(*pose) : 0,
      header ? _fbb.CreateVector<uint8_t>(*header) : 0);
}

inline const simple_msgs::PoseStampedFbs *GetPoseStampedFbs(const void *buf) {
  return flatbuffers::GetRoot<simple_msgs::PoseStampedFbs>(buf);
}

inline const simple_msgs::PoseStampedFbs *GetSizePrefixedPoseStampedFbs(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<simple_msgs::PoseStampedFbs>(buf);
}

inline const char *PoseStampedFbsIdentifier() {
  return "POST";
}

inline bool PoseStampedFbsBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, PoseStampedFbsIdentifier());
}

inline bool VerifyPoseStampedFbsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<simple_msgs::PoseStampedFbs>(PoseStampedFbsIdentifier());
}

inline bool VerifySizePrefixedPoseStampedFbsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<simple_msgs::PoseStampedFbs>(PoseStampedFbsIdentifier());
}

inline void FinishPoseStampedFbsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<simple_msgs::PoseStampedFbs> root) {
  fbb.Finish(root, PoseStampedFbsIdentifier());
}

inline void FinishSizePrefixedPoseStampedFbsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<simple_msgs::PoseStampedFbs> root) {
  fbb.FinishSizePrefixed(root, PoseStampedFbsIdentifier());
}

}  // namespace simple_msgs

#endif  // FLATBUFFERS_GENERATED_POSESTAMPED_SIMPLE_MSGS_H_