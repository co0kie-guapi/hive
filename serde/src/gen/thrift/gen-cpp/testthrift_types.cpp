/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "testthrift_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




InnerStruct::~InnerStruct() throw() {
}


void InnerStruct::__set_field0(const int32_t val) {
  this->field0 = val;
}

uint32_t InnerStruct::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->field0);
          this->__isset.field0 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InnerStruct::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InnerStruct");

  xfer += oprot->writeFieldBegin("field0", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->field0);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InnerStruct &a, InnerStruct &b) {
  using ::std::swap;
  swap(a.field0, b.field0);
  swap(a.__isset, b.__isset);
}

InnerStruct::InnerStruct(const InnerStruct& other0) {
  field0 = other0.field0;
  __isset = other0.__isset;
}
InnerStruct& InnerStruct::operator=(const InnerStruct& other1) {
  field0 = other1.field0;
  __isset = other1.__isset;
  return *this;
}
void InnerStruct::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InnerStruct(";
  out << "field0=" << to_string(field0);
  out << ")";
}


ThriftTestObj::~ThriftTestObj() throw() {
}


void ThriftTestObj::__set_field1(const int32_t val) {
  this->field1 = val;
}

void ThriftTestObj::__set_field2(const std::string& val) {
  this->field2 = val;
}

void ThriftTestObj::__set_field3(const std::vector<InnerStruct> & val) {
  this->field3 = val;
}

uint32_t ThriftTestObj::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->field1);
          this->__isset.field1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->field2);
          this->__isset.field2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->field3.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->field3.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += this->field3[_i6].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.field3 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ThriftTestObj::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftTestObj");

  xfer += oprot->writeFieldBegin("field1", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->field1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("field2", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->field2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("field3", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->field3.size()));
    std::vector<InnerStruct> ::const_iterator _iter7;
    for (_iter7 = this->field3.begin(); _iter7 != this->field3.end(); ++_iter7)
    {
      xfer += (*_iter7).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftTestObj &a, ThriftTestObj &b) {
  using ::std::swap;
  swap(a.field1, b.field1);
  swap(a.field2, b.field2);
  swap(a.field3, b.field3);
  swap(a.__isset, b.__isset);
}

ThriftTestObj::ThriftTestObj(const ThriftTestObj& other8) {
  field1 = other8.field1;
  field2 = other8.field2;
  field3 = other8.field3;
  __isset = other8.__isset;
}
ThriftTestObj& ThriftTestObj::operator=(const ThriftTestObj& other9) {
  field1 = other9.field1;
  field2 = other9.field2;
  field3 = other9.field3;
  __isset = other9.__isset;
  return *this;
}
void ThriftTestObj::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftTestObj(";
  out << "field1=" << to_string(field1);
  out << ", " << "field2=" << to_string(field2);
  out << ", " << "field3=" << to_string(field3);
  out << ")";
}

