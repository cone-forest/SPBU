#include <iostream>

int main() {
  double a;
  double b;
  double c;
  double d;

  std::cout << "Input a, b: ";
  std::cin >> a >> b;
  std::cout << "Input c, d: ";
  std::cin >> c >> d;

  double x;
  std::cin >> x;

  double i = ((x - a) / (b - a)) * (d - c) + c;

  std::cout << i << std::endl;
}
