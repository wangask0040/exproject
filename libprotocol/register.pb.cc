// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: register.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "register.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace pbregister {

namespace {

const ::google::protobuf::Descriptor* MsgRegisterReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MsgRegisterReq_reflection_ = NULL;
const ::google::protobuf::Descriptor* MsgRegisterRsp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MsgRegisterRsp_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_register_2eproto() {
  protobuf_AddDesc_register_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "register.proto");
  GOOGLE_CHECK(file != NULL);
  MsgRegisterReq_descriptor_ = file->message_type(0);
  static const int MsgRegisterReq_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterReq, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterReq, passwd_),
  };
  MsgRegisterReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MsgRegisterReq_descriptor_,
      MsgRegisterReq::default_instance_,
      MsgRegisterReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MsgRegisterReq));
  MsgRegisterRsp_descriptor_ = file->message_type(1);
  static const int MsgRegisterRsp_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterRsp, result_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterRsp, msg_),
  };
  MsgRegisterRsp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MsgRegisterRsp_descriptor_,
      MsgRegisterRsp::default_instance_,
      MsgRegisterRsp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterRsp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgRegisterRsp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MsgRegisterRsp));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_register_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MsgRegisterReq_descriptor_, &MsgRegisterReq::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MsgRegisterRsp_descriptor_, &MsgRegisterRsp::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_register_2eproto() {
  delete MsgRegisterReq::default_instance_;
  delete MsgRegisterReq_reflection_;
  delete MsgRegisterRsp::default_instance_;
  delete MsgRegisterRsp_reflection_;
}

void protobuf_AddDesc_register_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016register.proto\022\npbregister\"1\n\016MsgRegis"
    "terReq\022\017\n\007account\030\001 \002(\t\022\016\n\006passwd\030\002 \002(\t\""
    "-\n\016MsgRegisterRsp\022\016\n\006result\030\001 \002(\005\022\013\n\003msg"
    "\030\002 \002(\t", 126);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "register.proto", &protobuf_RegisterTypes);
  MsgRegisterReq::default_instance_ = new MsgRegisterReq();
  MsgRegisterRsp::default_instance_ = new MsgRegisterRsp();
  MsgRegisterReq::default_instance_->InitAsDefaultInstance();
  MsgRegisterRsp::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_register_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_register_2eproto {
  StaticDescriptorInitializer_register_2eproto() {
    protobuf_AddDesc_register_2eproto();
  }
} static_descriptor_initializer_register_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MsgRegisterReq::kAccountFieldNumber;
const int MsgRegisterReq::kPasswdFieldNumber;
#endif  // !_MSC_VER

MsgRegisterReq::MsgRegisterReq()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MsgRegisterReq::InitAsDefaultInstance() {
}

MsgRegisterReq::MsgRegisterReq(const MsgRegisterReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MsgRegisterReq::SharedCtor() {
  _cached_size_ = 0;
  account_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  passwd_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MsgRegisterReq::~MsgRegisterReq() {
  SharedDtor();
}

void MsgRegisterReq::SharedDtor() {
  if (account_ != &::google::protobuf::internal::kEmptyString) {
    delete account_;
  }
  if (passwd_ != &::google::protobuf::internal::kEmptyString) {
    delete passwd_;
  }
  if (this != default_instance_) {
  }
}

void MsgRegisterReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgRegisterReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgRegisterReq_descriptor_;
}

const MsgRegisterReq& MsgRegisterReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_register_2eproto();
  return *default_instance_;
}

MsgRegisterReq* MsgRegisterReq::default_instance_ = NULL;

MsgRegisterReq* MsgRegisterReq::New() const {
  return new MsgRegisterReq;
}

void MsgRegisterReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_account()) {
      if (account_ != &::google::protobuf::internal::kEmptyString) {
        account_->clear();
      }
    }
    if (has_passwd()) {
      if (passwd_ != &::google::protobuf::internal::kEmptyString) {
        passwd_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MsgRegisterReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string account = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_account()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->account().data(), this->account().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_passwd;
        break;
      }

      // required string passwd = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_passwd:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_passwd()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->passwd().data(), this->passwd().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MsgRegisterReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->account().data(), this->account().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->account(), output);
  }

  // required string passwd = 2;
  if (has_passwd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->passwd().data(), this->passwd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->passwd(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MsgRegisterReq::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->account().data(), this->account().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->account(), target);
  }

  // required string passwd = 2;
  if (has_passwd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->passwd().data(), this->passwd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->passwd(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MsgRegisterReq::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->account());
    }

    // required string passwd = 2;
    if (has_passwd()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->passwd());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MsgRegisterReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MsgRegisterReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MsgRegisterReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MsgRegisterReq::MergeFrom(const MsgRegisterReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      set_account(from.account());
    }
    if (from.has_passwd()) {
      set_passwd(from.passwd());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MsgRegisterReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgRegisterReq::CopyFrom(const MsgRegisterReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgRegisterReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void MsgRegisterReq::Swap(MsgRegisterReq* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(passwd_, other->passwd_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MsgRegisterReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MsgRegisterReq_descriptor_;
  metadata.reflection = MsgRegisterReq_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MsgRegisterRsp::kResultFieldNumber;
const int MsgRegisterRsp::kMsgFieldNumber;
#endif  // !_MSC_VER

MsgRegisterRsp::MsgRegisterRsp()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MsgRegisterRsp::InitAsDefaultInstance() {
}

MsgRegisterRsp::MsgRegisterRsp(const MsgRegisterRsp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MsgRegisterRsp::SharedCtor() {
  _cached_size_ = 0;
  result_ = 0;
  msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MsgRegisterRsp::~MsgRegisterRsp() {
  SharedDtor();
}

void MsgRegisterRsp::SharedDtor() {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    delete msg_;
  }
  if (this != default_instance_) {
  }
}

void MsgRegisterRsp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgRegisterRsp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgRegisterRsp_descriptor_;
}

const MsgRegisterRsp& MsgRegisterRsp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_register_2eproto();
  return *default_instance_;
}

MsgRegisterRsp* MsgRegisterRsp::default_instance_ = NULL;

MsgRegisterRsp* MsgRegisterRsp::New() const {
  return new MsgRegisterRsp;
}

void MsgRegisterRsp::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    result_ = 0;
    if (has_msg()) {
      if (msg_ != &::google::protobuf::internal::kEmptyString) {
        msg_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MsgRegisterRsp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 result = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &result_)));
          set_has_result();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_msg;
        break;
      }

      // required string msg = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_msg:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_msg()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->msg().data(), this->msg().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MsgRegisterRsp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 result = 1;
  if (has_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->result(), output);
  }

  // required string msg = 2;
  if (has_msg()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->msg().data(), this->msg().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->msg(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MsgRegisterRsp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 result = 1;
  if (has_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->result(), target);
  }

  // required string msg = 2;
  if (has_msg()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->msg().data(), this->msg().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->msg(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MsgRegisterRsp::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 result = 1;
    if (has_result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->result());
    }

    // required string msg = 2;
    if (has_msg()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->msg());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MsgRegisterRsp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MsgRegisterRsp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MsgRegisterRsp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MsgRegisterRsp::MergeFrom(const MsgRegisterRsp& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_result()) {
      set_result(from.result());
    }
    if (from.has_msg()) {
      set_msg(from.msg());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MsgRegisterRsp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgRegisterRsp::CopyFrom(const MsgRegisterRsp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgRegisterRsp::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void MsgRegisterRsp::Swap(MsgRegisterRsp* other) {
  if (other != this) {
    std::swap(result_, other->result_);
    std::swap(msg_, other->msg_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MsgRegisterRsp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MsgRegisterRsp_descriptor_;
  metadata.reflection = MsgRegisterRsp_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pbregister

// @@protoc_insertion_point(global_scope)
