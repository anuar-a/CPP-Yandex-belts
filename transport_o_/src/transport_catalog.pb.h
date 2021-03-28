// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transport_catalog.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_transport_5fcatalog_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_transport_5fcatalog_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_transport_5fcatalog_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_transport_5fcatalog_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[5]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transport_5fcatalog_2eproto;
namespace Serializer {
class BusStopResponse;
class BusStopResponseDefaultTypeInternal;
extern BusStopResponseDefaultTypeInternal _BusStopResponse_default_instance_;
class RouteResponse;
class RouteResponseDefaultTypeInternal;
extern RouteResponseDefaultTypeInternal _RouteResponse_default_instance_;
class TransportCatalog;
class TransportCatalogDefaultTypeInternal;
extern TransportCatalogDefaultTypeInternal _TransportCatalog_default_instance_;
class TransportCatalog_RouteResponsesEntry_DoNotUse;
class TransportCatalog_RouteResponsesEntry_DoNotUseDefaultTypeInternal;
extern TransportCatalog_RouteResponsesEntry_DoNotUseDefaultTypeInternal _TransportCatalog_RouteResponsesEntry_DoNotUse_default_instance_;
class TransportCatalog_StopResponsesEntry_DoNotUse;
class TransportCatalog_StopResponsesEntry_DoNotUseDefaultTypeInternal;
extern TransportCatalog_StopResponsesEntry_DoNotUseDefaultTypeInternal _TransportCatalog_StopResponsesEntry_DoNotUse_default_instance_;
}  // namespace Serializer
PROTOBUF_NAMESPACE_OPEN
template<> ::Serializer::BusStopResponse* Arena::CreateMaybeMessage<::Serializer::BusStopResponse>(Arena*);
template<> ::Serializer::RouteResponse* Arena::CreateMaybeMessage<::Serializer::RouteResponse>(Arena*);
template<> ::Serializer::TransportCatalog* Arena::CreateMaybeMessage<::Serializer::TransportCatalog>(Arena*);
template<> ::Serializer::TransportCatalog_RouteResponsesEntry_DoNotUse* Arena::CreateMaybeMessage<::Serializer::TransportCatalog_RouteResponsesEntry_DoNotUse>(Arena*);
template<> ::Serializer::TransportCatalog_StopResponsesEntry_DoNotUse* Arena::CreateMaybeMessage<::Serializer::TransportCatalog_StopResponsesEntry_DoNotUse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Serializer {

// ===================================================================

class BusStopResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Serializer.BusStopResponse) */ {
 public:
  BusStopResponse();
  virtual ~BusStopResponse();

  BusStopResponse(const BusStopResponse& from);
  BusStopResponse(BusStopResponse&& from) noexcept
    : BusStopResponse() {
    *this = ::std::move(from);
  }

  inline BusStopResponse& operator=(const BusStopResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline BusStopResponse& operator=(BusStopResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BusStopResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BusStopResponse* internal_default_instance() {
    return reinterpret_cast<const BusStopResponse*>(
               &_BusStopResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BusStopResponse& a, BusStopResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(BusStopResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BusStopResponse* New() const final {
    return CreateMaybeMessage<BusStopResponse>(nullptr);
  }

  BusStopResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BusStopResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BusStopResponse& from);
  void MergeFrom(const BusStopResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BusStopResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Serializer.BusStopResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transport_5fcatalog_2eproto);
    return ::descriptor_table_transport_5fcatalog_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBusesOnStopFieldNumber = 1,
  };
  // repeated string buses_on_stop = 1;
  int buses_on_stop_size() const;
  void clear_buses_on_stop();
  const std::string& buses_on_stop(int index) const;
  std::string* mutable_buses_on_stop(int index);
  void set_buses_on_stop(int index, const std::string& value);
  void set_buses_on_stop(int index, std::string&& value);
  void set_buses_on_stop(int index, const char* value);
  void set_buses_on_stop(int index, const char* value, size_t size);
  std::string* add_buses_on_stop();
  void add_buses_on_stop(const std::string& value);
  void add_buses_on_stop(std::string&& value);
  void add_buses_on_stop(const char* value);
  void add_buses_on_stop(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& buses_on_stop() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_buses_on_stop();

  // @@protoc_insertion_point(class_scope:Serializer.BusStopResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> buses_on_stop_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transport_5fcatalog_2eproto;
};
// -------------------------------------------------------------------

class RouteResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Serializer.RouteResponse) */ {
 public:
  RouteResponse();
  virtual ~RouteResponse();

  RouteResponse(const RouteResponse& from);
  RouteResponse(RouteResponse&& from) noexcept
    : RouteResponse() {
    *this = ::std::move(from);
  }

  inline RouteResponse& operator=(const RouteResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline RouteResponse& operator=(RouteResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RouteResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RouteResponse* internal_default_instance() {
    return reinterpret_cast<const RouteResponse*>(
               &_RouteResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(RouteResponse& a, RouteResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(RouteResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RouteResponse* New() const final {
    return CreateMaybeMessage<RouteResponse>(nullptr);
  }

  RouteResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RouteResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RouteResponse& from);
  void MergeFrom(const RouteResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RouteResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Serializer.RouteResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transport_5fcatalog_2eproto);
    return ::descriptor_table_transport_5fcatalog_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStopsOnRouteFieldNumber = 1,
    kUniqueStopsFieldNumber = 2,
    kRouteLengthFieldNumber = 3,
    kCurvatureFieldNumber = 4,
  };
  // int32 stops_on_route = 1;
  void clear_stops_on_route();
  ::PROTOBUF_NAMESPACE_ID::int32 stops_on_route() const;
  void set_stops_on_route(::PROTOBUF_NAMESPACE_ID::int32 value);

  // int32 unique_stops = 2;
  void clear_unique_stops();
  ::PROTOBUF_NAMESPACE_ID::int32 unique_stops() const;
  void set_unique_stops(::PROTOBUF_NAMESPACE_ID::int32 value);

  // uint32 route_length = 3;
  void clear_route_length();
  ::PROTOBUF_NAMESPACE_ID::uint32 route_length() const;
  void set_route_length(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // float curvature = 4;
  void clear_curvature();
  float curvature() const;
  void set_curvature(float value);

  // @@protoc_insertion_point(class_scope:Serializer.RouteResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::int32 stops_on_route_;
  ::PROTOBUF_NAMESPACE_ID::int32 unique_stops_;
  ::PROTOBUF_NAMESPACE_ID::uint32 route_length_;
  float curvature_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transport_5fcatalog_2eproto;
};
// -------------------------------------------------------------------

class TransportCatalog_StopResponsesEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<TransportCatalog_StopResponsesEntry_DoNotUse, 
    std::string, ::Serializer::BusStopResponse,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
    0 > {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<TransportCatalog_StopResponsesEntry_DoNotUse, 
    std::string, ::Serializer::BusStopResponse,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
    0 > SuperType;
  TransportCatalog_StopResponsesEntry_DoNotUse();
  TransportCatalog_StopResponsesEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const TransportCatalog_StopResponsesEntry_DoNotUse& other);
  static const TransportCatalog_StopResponsesEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const TransportCatalog_StopResponsesEntry_DoNotUse*>(&_TransportCatalog_StopResponsesEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), s->size(), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "Serializer.TransportCatalog.StopResponsesEntry.key");
 }
  static bool ValidateValue(void*) { return true; }
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& other) final;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transport_5fcatalog_2eproto);
    return ::descriptor_table_transport_5fcatalog_2eproto.file_level_metadata[2];
  }

  public:
};

// -------------------------------------------------------------------

class TransportCatalog_RouteResponsesEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<TransportCatalog_RouteResponsesEntry_DoNotUse, 
    std::string, ::Serializer::RouteResponse,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
    0 > {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<TransportCatalog_RouteResponsesEntry_DoNotUse, 
    std::string, ::Serializer::RouteResponse,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
    0 > SuperType;
  TransportCatalog_RouteResponsesEntry_DoNotUse();
  TransportCatalog_RouteResponsesEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const TransportCatalog_RouteResponsesEntry_DoNotUse& other);
  static const TransportCatalog_RouteResponsesEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const TransportCatalog_RouteResponsesEntry_DoNotUse*>(&_TransportCatalog_RouteResponsesEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), s->size(), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "Serializer.TransportCatalog.RouteResponsesEntry.key");
 }
  static bool ValidateValue(void*) { return true; }
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& other) final;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transport_5fcatalog_2eproto);
    return ::descriptor_table_transport_5fcatalog_2eproto.file_level_metadata[3];
  }

  public:
};

// -------------------------------------------------------------------

class TransportCatalog :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Serializer.TransportCatalog) */ {
 public:
  TransportCatalog();
  virtual ~TransportCatalog();

  TransportCatalog(const TransportCatalog& from);
  TransportCatalog(TransportCatalog&& from) noexcept
    : TransportCatalog() {
    *this = ::std::move(from);
  }

  inline TransportCatalog& operator=(const TransportCatalog& from) {
    CopyFrom(from);
    return *this;
  }
  inline TransportCatalog& operator=(TransportCatalog&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const TransportCatalog& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TransportCatalog* internal_default_instance() {
    return reinterpret_cast<const TransportCatalog*>(
               &_TransportCatalog_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  friend void swap(TransportCatalog& a, TransportCatalog& b) {
    a.Swap(&b);
  }
  inline void Swap(TransportCatalog* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline TransportCatalog* New() const final {
    return CreateMaybeMessage<TransportCatalog>(nullptr);
  }

  TransportCatalog* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<TransportCatalog>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const TransportCatalog& from);
  void MergeFrom(const TransportCatalog& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TransportCatalog* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Serializer.TransportCatalog";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_transport_5fcatalog_2eproto);
    return ::descriptor_table_transport_5fcatalog_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  enum : int {
    kStopResponsesFieldNumber = 1,
    kRouteResponsesFieldNumber = 2,
  };
  // map<string, .Serializer.BusStopResponse> stop_responses = 1;
  int stop_responses_size() const;
  void clear_stop_responses();
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::BusStopResponse >&
      stop_responses() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::BusStopResponse >*
      mutable_stop_responses();

  // map<string, .Serializer.RouteResponse> route_responses = 2;
  int route_responses_size() const;
  void clear_route_responses();
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::RouteResponse >&
      route_responses() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::RouteResponse >*
      mutable_route_responses();

  // @@protoc_insertion_point(class_scope:Serializer.TransportCatalog)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::MapField<
      TransportCatalog_StopResponsesEntry_DoNotUse,
      std::string, ::Serializer::BusStopResponse,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
      0 > stop_responses_;
  ::PROTOBUF_NAMESPACE_ID::internal::MapField<
      TransportCatalog_RouteResponsesEntry_DoNotUse,
      std::string, ::Serializer::RouteResponse,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE,
      0 > route_responses_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transport_5fcatalog_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BusStopResponse

// repeated string buses_on_stop = 1;
inline int BusStopResponse::buses_on_stop_size() const {
  return buses_on_stop_.size();
}
inline void BusStopResponse::clear_buses_on_stop() {
  buses_on_stop_.Clear();
}
inline const std::string& BusStopResponse::buses_on_stop(int index) const {
  // @@protoc_insertion_point(field_get:Serializer.BusStopResponse.buses_on_stop)
  return buses_on_stop_.Get(index);
}
inline std::string* BusStopResponse::mutable_buses_on_stop(int index) {
  // @@protoc_insertion_point(field_mutable:Serializer.BusStopResponse.buses_on_stop)
  return buses_on_stop_.Mutable(index);
}
inline void BusStopResponse::set_buses_on_stop(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:Serializer.BusStopResponse.buses_on_stop)
  buses_on_stop_.Mutable(index)->assign(value);
}
inline void BusStopResponse::set_buses_on_stop(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:Serializer.BusStopResponse.buses_on_stop)
  buses_on_stop_.Mutable(index)->assign(std::move(value));
}
inline void BusStopResponse::set_buses_on_stop(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  buses_on_stop_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Serializer.BusStopResponse.buses_on_stop)
}
inline void BusStopResponse::set_buses_on_stop(int index, const char* value, size_t size) {
  buses_on_stop_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Serializer.BusStopResponse.buses_on_stop)
}
inline std::string* BusStopResponse::add_buses_on_stop() {
  // @@protoc_insertion_point(field_add_mutable:Serializer.BusStopResponse.buses_on_stop)
  return buses_on_stop_.Add();
}
inline void BusStopResponse::add_buses_on_stop(const std::string& value) {
  buses_on_stop_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Serializer.BusStopResponse.buses_on_stop)
}
inline void BusStopResponse::add_buses_on_stop(std::string&& value) {
  buses_on_stop_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:Serializer.BusStopResponse.buses_on_stop)
}
inline void BusStopResponse::add_buses_on_stop(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  buses_on_stop_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Serializer.BusStopResponse.buses_on_stop)
}
inline void BusStopResponse::add_buses_on_stop(const char* value, size_t size) {
  buses_on_stop_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Serializer.BusStopResponse.buses_on_stop)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
BusStopResponse::buses_on_stop() const {
  // @@protoc_insertion_point(field_list:Serializer.BusStopResponse.buses_on_stop)
  return buses_on_stop_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
BusStopResponse::mutable_buses_on_stop() {
  // @@protoc_insertion_point(field_mutable_list:Serializer.BusStopResponse.buses_on_stop)
  return &buses_on_stop_;
}

// -------------------------------------------------------------------

// RouteResponse

// int32 stops_on_route = 1;
inline void RouteResponse::clear_stops_on_route() {
  stops_on_route_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RouteResponse::stops_on_route() const {
  // @@protoc_insertion_point(field_get:Serializer.RouteResponse.stops_on_route)
  return stops_on_route_;
}
inline void RouteResponse::set_stops_on_route(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  stops_on_route_ = value;
  // @@protoc_insertion_point(field_set:Serializer.RouteResponse.stops_on_route)
}

// int32 unique_stops = 2;
inline void RouteResponse::clear_unique_stops() {
  unique_stops_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RouteResponse::unique_stops() const {
  // @@protoc_insertion_point(field_get:Serializer.RouteResponse.unique_stops)
  return unique_stops_;
}
inline void RouteResponse::set_unique_stops(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  unique_stops_ = value;
  // @@protoc_insertion_point(field_set:Serializer.RouteResponse.unique_stops)
}

// uint32 route_length = 3;
inline void RouteResponse::clear_route_length() {
  route_length_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 RouteResponse::route_length() const {
  // @@protoc_insertion_point(field_get:Serializer.RouteResponse.route_length)
  return route_length_;
}
inline void RouteResponse::set_route_length(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  route_length_ = value;
  // @@protoc_insertion_point(field_set:Serializer.RouteResponse.route_length)
}

// float curvature = 4;
inline void RouteResponse::clear_curvature() {
  curvature_ = 0;
}
inline float RouteResponse::curvature() const {
  // @@protoc_insertion_point(field_get:Serializer.RouteResponse.curvature)
  return curvature_;
}
inline void RouteResponse::set_curvature(float value) {
  
  curvature_ = value;
  // @@protoc_insertion_point(field_set:Serializer.RouteResponse.curvature)
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// TransportCatalog

// map<string, .Serializer.BusStopResponse> stop_responses = 1;
inline int TransportCatalog::stop_responses_size() const {
  return stop_responses_.size();
}
inline void TransportCatalog::clear_stop_responses() {
  stop_responses_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::BusStopResponse >&
TransportCatalog::stop_responses() const {
  // @@protoc_insertion_point(field_map:Serializer.TransportCatalog.stop_responses)
  return stop_responses_.GetMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::BusStopResponse >*
TransportCatalog::mutable_stop_responses() {
  // @@protoc_insertion_point(field_mutable_map:Serializer.TransportCatalog.stop_responses)
  return stop_responses_.MutableMap();
}

// map<string, .Serializer.RouteResponse> route_responses = 2;
inline int TransportCatalog::route_responses_size() const {
  return route_responses_.size();
}
inline void TransportCatalog::clear_route_responses() {
  route_responses_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::RouteResponse >&
TransportCatalog::route_responses() const {
  // @@protoc_insertion_point(field_map:Serializer.TransportCatalog.route_responses)
  return route_responses_.GetMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::Serializer::RouteResponse >*
TransportCatalog::mutable_route_responses() {
  // @@protoc_insertion_point(field_mutable_map:Serializer.TransportCatalog.route_responses)
  return route_responses_.MutableMap();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serializer

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_transport_5fcatalog_2eproto
