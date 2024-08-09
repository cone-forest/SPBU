#include <iostream>
#include <cmath>

void outputSolution(double a, double b, double c) {
  static constexpr double E = 0.01;

  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        std::cout << "All real numbers" << std::endl;
      } else {
        std::cout << "Empty set" << std::endl;
      }
    } else {
      std::cout << -c / b << std::endl;
    }
  } else {
    double D = std::pow(b, 2) - 4 * a * c;

    if (D > 0) {
      // 2 real solutions
      std::cout << "{" << (-b - std::sqrt(D)) / (2 * a) << ", ";
      std::cout << (-b + std::sqrt(D)) / (2 * a) << "}" << std::endl;
    } else if (D == 0) {
      // 1 real solutions
      std::cout << (-b / (2 * a)) << std::endl;
    } else {
      // 0 real solutions
      std::cout << "{" << (-b / (2 * a)) << " + i" << std::sqrt(-D) / (2 * a) << ", ";
      std::cout << (-b / (2 * a)) << " - i" << std::sqrt(-D) / (2 * a) << "}" << std::endl;
    }
  }
}

int main() {
  double a;
  double b;
  double c;

  std::cout << "TESTS:" << std::endl;

  a = 1, b = 0, c = 0;
  printf("(%f, %f, %f)\n", a, b, c);
  outputSolution(a, b, c);
  std::cout << std::endl;

  a = 0, b = 0, c = 0;
  printf("(%f, %f, %f)\n", a, b, c);
  outputSolution(a, b, c);
  std::cout << std::endl;

  a = 0, b = 0, c = 1;
  printf("(%f, %f, %f)\n", a, b, c);
  outputSolution(a, b, c);
  std::cout << std::endl;

  a = 0, b = 1, c = 1;
  printf("(%f, %f, %f)\n", a, b, c);
  outputSolution(a, b, c);
  std::cout << std::endl;

  a = 1, b = 1, c = 1;
  printf("(%f, %f, %f)\n", a, b, c);
  outputSolution(a, b, c);
  std::cout << std::endl;

  a = 1, b = 2, c = 1;
  printf("(%f, %f, %f)\n", a, b, c);
  outputSolution(a, b, c);
  std::cout << std::endl;
}
