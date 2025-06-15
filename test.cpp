#include <memory>
#include <iostream>

class Ball {
  public:
    Ball() {
      std:: cout << "A ball appears" << std::endl;
    }
    ~Ball() {
      std::cout << "A ball disappears" << std::endl;
    }
};

void custom_deleter(Ball* ptr) {
  std::cout << "Custom deleter" << std::endl;
}

int main() {
  Ball b;
  std::cout << "Start" << std::endl;
  // The code below only shows how to initialize a shared_pointer to an existing object,
  // Can use a custom_deleter, so the object won't be deleted after the pointer is out of scope.
  // but DON'T initialize the shared_pointer with a raw pointer! It's bad flavor!
  // And don't do this multiple times! It's a disaster.
  std::shared_ptr<Ball> p1(&b, custom_deleter);
  std::shared_ptr<Ball> p2(&b, custom_deleter);
  // You can see these 2 pointers have separate ref counts on b. It's not okay.
  std::cout << p1.use_count() << " and " << p2.use_count() << std::endl;
  return 0;
}
