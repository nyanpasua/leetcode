
#include <algorithm>
namespace alpha {
// 实现的最大问题是，它的行为会让程序员非常容易犯错。
// 一不小心把它传递给另外一个 auto_ptr，你就不再拥有这个对象了……
template <class T>
class auto_ptr {
 public:
  explicit auto_ptr(T* ptr) : ptr_(ptr) {}
  ~auto_ptr() { delete ptr_; }

  // other 指针被置为 nullptr，lhs 接管 other 指针
  auto_ptr(auto_ptr& other) { ptr_ = other.release(); }
  // Right Hand Side
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




}  // namespace alpha