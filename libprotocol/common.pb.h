// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common.proto

#ifndef PROTOBUF_common_2eproto__INCLUDED
#define PROTOBUF_common_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace pbcommon {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_common_2eproto();
void protobuf_AssignDesc_common_2eproto();
void protobuf_ShutdownFile_common_2eproto();

class MsgHead;
class MsgBody;

// ===================================================================

class MsgHead : public ::google::protobuf::Message {
 public:
  MsgHead();
  virtual ~MsgHead();

  MsgHead(const MsgHead& from);

  inline MsgHead& operator=(const MsgHead& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgHead& default_instance();

  void Swap(MsgHead* other);

  // implements Message ----------------------------------------------

  MsgHead* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MsgHead& from);
  void MergeFrom(const MsgHead& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // required int32 bodylen = 2;
  inline bool has_bodylen() const;
  inline void clear_bodylen();
  static const int kBodylenFieldNumber = 2;
  inline ::google::protobuf::int32 bodylen() const;
  inline void set_bodylen(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:pbcommon.MsgHead)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_bodylen();
  inline void clear_has_bodylen();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 bodylen_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static MsgHead* default_instance_;
};
// -------------------------------------------------------------------

class MsgBody : public ::google::protobuf::Message {
 public:
  MsgBody();
  virtual ~MsgBody();

  MsgBody(const MsgBody& from);

  inline MsgBody& operator=(const MsgBody& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgBody& default_instance();

  void Swap(MsgBody* other);

  // implements Message ----------------------------------------------

  MsgBody* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MsgBody& from);
  void MergeFrom(const MsgBody& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 bodylen = 1;
  inline bool has_bodylen() const;
  inline void clear_bodylen();
  static const int kBodylenFieldNumber = 1;
  inline ::google::protobuf::int32 bodylen() const;
  inline void set_bodylen(::google::protobuf::int32 value);

  // required string body = 2;
  inline bool has_body() const;
  inline void clear_body();
  static const int kBodyFieldNumber = 2;
  inline const ::std::string& body() const;
  inline void set_body(const ::std::string& value);
  inline void set_body(const char* value);
  inline void set_body(const char* value, size_t size);
  inline ::std::string* mutable_body();
  inline ::std::string* release_body();
  inline void set_allocated_body(::std::string* body);

  // @@protoc_insertion_point(class_scope:pbcommon.MsgBody)
 private:
  inline void set_has_bodylen();
  inline void clear_has_bodylen();
  inline void set_has_body();
  inline void clear_has_body();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* body_;
  ::google::protobuf::int32 bodylen_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static MsgBody* default_instance_;
};
// ===================================================================


// ===================================================================

// MsgHead

// required int32 type = 1;
inline bool MsgHead::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MsgHead::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MsgHead::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MsgHead::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 MsgHead::type() const {
  return type_;
}
inline void MsgHead::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// required int32 bodylen = 2;
inline bool MsgHead::has_bodylen() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MsgHead::set_has_bodylen() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MsgHead::clear_has_bodylen() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MsgHead::clear_bodylen() {
  bodylen_ = 0;
  clear_has_bodylen();
}
inline ::google::protobuf::int32 MsgHead::bodylen() const {
  return bodylen_;
}
inline void MsgHead::set_bodylen(::google::protobuf::int32 value) {
  set_has_bodylen();
  bodylen_ = value;
}

// -------------------------------------------------------------------

// MsgBody

// required int32 bodylen = 1;
inline bool MsgBody::has_bodylen() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MsgBody::set_has_bodylen() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MsgBody::clear_has_bodylen() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MsgBody::clear_bodylen() {
  bodylen_ = 0;
  clear_has_bodylen();
}
inline ::google::protobuf::int32 MsgBody::bodylen() const {
  return bodylen_;
}
inline void MsgBody::set_bodylen(::google::protobuf::int32 value) {
  set_has_bodylen();
  bodylen_ = value;
}

// required string body = 2;
inline bool MsgBody::has_body() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MsgBody::set_has_body() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MsgBody::clear_has_body() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MsgBody::clear_body() {
  if (body_ != &::google::protobuf::internal::kEmptyString) {
    body_->clear();
  }
  clear_has_body();
}
inline const ::std::string& MsgBody::body() const {
  return *body_;
}
inline void MsgBody::set_body(const ::std::string& value) {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  body_->assign(value);
}
inline void MsgBody::set_body(const char* value) {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  body_->assign(value);
}
inline void MsgBody::set_body(const char* value, size_t size) {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  body_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MsgBody::mutable_body() {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  return body_;
}
inline ::std::string* MsgBody::release_body() {
  clear_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = body_;
    body_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void MsgBody::set_allocated_body(::std::string* body) {
  if (body_ != &::google::protobuf::internal::kEmptyString) {
    delete body_;
  }
  if (body) {
    set_has_body();
    body_ = body;
  } else {
    clear_has_body();
    body_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pbcommon

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_common_2eproto__INCLUDED
