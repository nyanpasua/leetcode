
#pragma once

#include <algorithm>
namespace alpha {
// 实现的最大问题是，它的行为会让程序员非常容易犯错。
// 一不小心把它传递给另外一个 auto_ptr，你就不再拥有这个对象了……
template <class T>
class auto_ptr {
 public:
  explicit auto_ptr(T* ptr) : ptr_(ptr) {}
  ~auto_ptr() { delete ptr_; }
  // 在拷贝的时候转移所有权
  // 拷贝构造，other 指针被置为 nullptr，lhs 接管 other 指针
  auto_ptr(auto_ptr& other) { ptr_ = other.release(); }
  // 拷贝赋值，Right Hand Side
  auto_ptr& operator=(auto_ptr& rhs) {
    // the copy-and-swap idiom
    // 这里拷贝构造一个临时对象，这个临时对象接管了 rhs
    // 的指针，进而与当前的指针交换，交换后，当前 lhs 指针拿到 rhs 的指针
    // 临时指针在行结束即被销毁，也就是 lhs 之前管理的指针被销毁
    auto_ptr(rhs).swap(*this);
    return *this;
  }

  T* get() const { return ptr_; }
  T& operator*() const { return &ptr_; }
  T* operator->() const { return ptr_; }
  operator bool() const { return ptr_ != nullptr; }

 private:
  void swap(auto_ptr& rhs) {
    using ::std::swap;
    swap(ptr_, rhs.ptr_);
  }
  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }
  T* ptr_;
};

template <typename T>
class unique_ptr {
 public:
  // 使得模板之间可以相互访问对方的 ptr_
  template <typename U>
  friend class unique_ptr;
  /// 构造函数
  explicit unique_ptr(T* ptr) : ptr_(ptr) {}
  ~unique_ptr() { delete ptr_; }
  /// 拷贝/移动构造：入参是 unique_ptr 类型
  // unique_ptr
  // 将禁用拷贝，如果定义了移动构造而没有定义拷贝构造，
  // 那么后者将自动被禁用，因此 unique_ptr 的构造参数不能是左值对象；
  // 移动构造函数，将转移所有权
  unique_ptr(unique_ptr&& other) { ptr_ = other.release(); }
  /// 隐式转换
  // 支持子类指针向基类指针的 隐式转换；
  // 但要注意，编译器不会将其视作 unique_ptr<T> 的移动构造函数
  // 因此不会产生默认禁用行为！
  template <typename U>
  unique_ptr(unique_ptr<U>&& other) {
    // 利用 指针 对于 子类向基类 转换的支持
    ptr_ = other.release();
  }
  // 手动禁用拷贝构造
  template <class U>
  unique_ptr(const unique_ptr<U>& other) = delete;

  // 手动禁用拷贝赋值
  template <class U>
  unique_ptr& operator=(const unique_ptr<U>& rhs) = delete;

  /// 拷贝/移动赋值：重定义 operator =
  // pass by value 的传递参数，因此 rhs 的构造会被调用；
  // 由于禁用了拷贝构造，因此只有移动构造函数可以被调用；
  // 赋值函数的行为是移动还是拷贝，完全取决于 构造 rhs 参数时，
  // 走的是移动构造还是拷贝构造；
  // 如果自定义赋值函数（operator =），编译器默认定义的会被删除；
  // 编译器不会区分拷贝赋值和移动赋值，只要有自定义 operator = ，就都删除；
  // 自定义 operator =
  unique_ptr& operator=(unique_ptr rhs) {
    rhs.swap(*this);
    return *this;
  }

  T* get() const { return ptr_; }
  T& operator*() const { return &ptr_; }
  T* operator->() const { return ptr_; }
  operator bool() const { return ptr_ != nullptr; }

 private:
  void swap(unique_ptr& rhs) {
    using ::std::swap;
    swap(ptr_, rhs.ptr_);
  }
  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }
  T* ptr_;
};

class shared_count {
 public:
  shared_count() noexcept : count_(1) {}
  void add_count() noexcept { ++count_; }
  long reduce_count() noexcept {
    // 返回 -1 之后的值
    return --count_;
  }
  long get_count() const noexcept { return count_; }

 private:
  long count_;
};

template <typename T>
class shared_ptr {
 public:
  template <typename U>
  friend class shared_ptr;
  /// 构造函数
  explicit shared_ptr(T* ptr = nullptr) : ptr_(ptr) {
    if (ptr) {
      shared_count_ = new shared_count();
    }
  }
  ~shared_ptr() {
    if (ptr_ && !shared_count_->reduce_count()) {
      delete ptr_;
      delete shared_count_;
    }
  }
  /// 拷贝/移动构造：入参是 const shared_ptr& 或者 shared_ptr&& 类型
  shared_ptr(const shared_ptr& other) {
    ptr_ = other.ptr_;
    if (ptr_) {
      other.shared_count_->add_count();
      shared_count_ = other.shared_count_;
    }
  }

  shared_ptr(shared_ptr&& other) noexcept {
    // 指针来判断是否能否完成转换
    ptr_ = other.ptr_;
    if (ptr_) {
      shared_count_ = other.shared_count_;
      other.ptr_ = nullptr;
    }
  }

  /// 隐式转换：构造
  // 隐式拷贝构造
  template <typename U>
  shared_ptr(const shared_ptr<U>& other) noexcept {
    ptr_ = other.ptr_;
    if (ptr_) {
      other.shared_count_->add_count();
      shared_count_ = other.shared_count_;
    }
  }
  // 隐式移动构造
  template <typename U>
  shared_ptr(shared_ptr<U>&& other) noexcept {
    // 指针来判断是否能否完成转换
    ptr_ = other.ptr_;
    if (ptr_) {
      shared_count_ = other.shared_count_;
      other.ptr_ = nullptr;
    }
  }

  /// 通用的拷贝/移动赋值：重定义 operator =
  // 对左值和右值均有效，且避免了 &rhs != this 的判断
  shared_ptr& operator=(shared_ptr rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  /// 非隐式转换构造函数
  template shared_ptr(const shared_ptr& other, T* ptr) noexcept {
    ptr_ = ptr;
    if (ptr_) {
      other.shared_count_->add_count();
      shared_count_ = other.shared_count_;
    }
  }

  /// pointer-like function
  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  // 隐式类型转换 bool
  operator bool() const noexcept { return ptr_; }
  T* get() const noexcept { return ptr_; }
  long use_count() const noexcept {
    if (ptr_) {
      return shared_count_->get_count();
    } else {
      return 0;
    }
  }
  void swap(shared_ptr& rhs) noexcept {
    using std::swap;
    swap(ptr_, rhs.ptr_);
    swap(shared_count_, rhs.shared_count_);
  }

 private:
  T* ptr_;
  shared_count* shared_count_;
};

template <typename T>
void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs) noexcept {
  lhs.swap(rhs);
}

// U -> T 侧 cast
template <typename T, typename U>
shared_ptr<T> static_pointer_cast(const shared_ptr<U>& other) noexcept {
  T* ptr = static_cast(other.get());
  // 构造 shared_ptr，使用 other 的引用计数
  return shared_ptr<T>(other, ptr);
}
template <typename T, typename U>
shared_ptr<T> reinterpret_pointer_cast(const shared_ptr<U>& other) noexcept {
  T* ptr = reinterpret_cast(other.get());
  return shared_ptr<T>(other, ptr);
}
template <typename T, typename U>
shared_ptr<T> const_pointer_cast(const shared_ptr<U>& other) noexcept {
  T* ptr = const_cast(other.get());
  return shared_ptr<T>(other, ptr);
}
template <typename T, typename U>
shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U>& other) noexcept {
  T* ptr = dynamic_cast(other.get());
  return shared_ptr<T>(other, ptr);
}

}  // namespace alpha