#include <iostream>
#include <cmath>

int main() {
  double r;
  double R;

  std::cout << "R: ";
  std::cin >> R;
  std::cout << "r: ";
  std::cin >> r;

  double x, y;
  std::cout << "x y: ";
  std::cin >> x >> y;

  if (std::pow(x, 2) + std::pow(y, 2) < std::pow(R, 2) &&
      std::pow(x, 2) + std::pow(y, 2) > std::pow(r, 2)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }
}
