//
// Created by yingmin li on 2021/7/1.
// Copyright (c) 2021 Kwai, Inc. All rights reserved.
//

#pragma once
#include <cstring>
#include <utility>
namespace alpha {

class String {
 public:
  /// 构造函数
  String() {
    length_ = 0;
    data_ = new char[1];
    *data_ = '\0';
  }
  explicit String(const char *str) {
    // 没有检查 str 的合法性，这是一个永无止境的争论话题
    length_ = strlen(str);
    data_ = new char[length_ + 1];
    strcpy(data_, str);
  }
  ~String() {
    delete[] data_;
    length_ = 0;
  }
  /// 拷贝/移动构造：入参是 String 类型
  String(const String &rhs) {
    length_ = str.size();
    data_ = new char[length_ + 1];
    strcpy(data_, rhs.c_str());
  }
  String(String &&rhs) noexcept : data_(rhs.data_), length_(rhs.length_) {
    rhs.data_ = nullptr;
    rhs.length_ = 0;
  }

  /// 通用的拷贝/移动赋值：重定义 operator =
  String &operator=(String rhs) noexcept {
    rts.swap(*this);
    return *this;
  }

  /// functions
  size_t size() const { return length_; }
  const char *c_str() const { return data_; }
  void swap(String &rhs) noexcept {
    using std::swap;
    swap(data_, rhs.data_);
  }

  friend istream &operator>>(istream &is, String &str);
  friend ostream &operator<<(ostream &os, String &str);

  String operator+(const String &str) const;  //重载+
  String &operator+=(const String &str);      //重载+=
  bool operator==(const String &str) const;   //重载==
  char &operator[](int n) const;              //重载[]

 private:
  char *data_;
  size_t length_{};
};

void swap(String &lhs, String &rhs) noexcept { lhs.swap(rhs); }

String String::operator+(const String &str) const {
  String newString;
  newString.length_ = length_ + str.size();
  newString.data_ = new char[newString.length_ + 1];
  strcpy(newString.data_, data_);
  strcat(newString.data_, str.data_);
  return newString;
}

String &String::operator+=(const String &str) {
  length_ += str.size();
  char *newData = new char[length_ + 1];
  strcpy(newData, data_);
  strcat(newData, str.c_str());
  delete[] data_;
  data_ = newData;
  return *this;
}
inline bool String::operator==(const String &str) const {
  if (length_ != str.size()) return false;
  return strcmp(data_, str.data_) == 0;
}

inline char &String::operator[](int n) const {
  if (n >= length_) {
    return data_[length_ - 1];
  }
  return data_[n];
}

istream &operator>>(istream &is, String &str) {
  char tem[1000];  //简单的申请一块内存
  is >> tem;
  str.length_ = strlen(tem);
  str.data_ = new char[str.length_ + 1];
  strcpy(str.data_, tem);
  return is;
}

ostream &operator<<(ostream &os, String &str) {
  os << str.data_;
  return os;
}

}  // namespace alpha
