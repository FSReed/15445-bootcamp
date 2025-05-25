#include <vector>
#include <algorithm>

#include <iostream>

int main() {
  std::vector<int> a {1, 2, 3, 4, 5, 6};
  auto result = std::remove_if(a.begin(), a.end(), [](const int &elem) {return elem % 2 == 0;});
  for (const int &elem : a) {
    std::cout << elem << std::endl;
  }
  return 0;
}
