#include <iostream>
#include <cmath>
#include <tuple>

long double log_series(long double x) {
  constexpr double E = 0.0001;
  long double d = x;
  long double ans = 0;
  long long i = 1;

  while (std::abs(d) > E && i < (1 << 10)) {
    ans += d;
    d *= -i * x / (i + 1);
    i++;
  }
  return ans;
}

long double invn_series() {
  constexpr double E = 0.00001;
  long n = 1;
  long double d = 1;
  long double ans = 0;

  while (std::abs(d) > E) {
    ans += d;
    d *= n / (double)(n + 1);
  }
  return ans;
}

long double pow2_series() {
  constexpr double E = 0.00001;
  long double d = 1;
  long double ans = 0;

  while (std::abs(d) > E) {
    ans += d;
    d /= 2;
  }
  return ans;
}

long double sin_series1(long double x, long n) {
  long double d = sin(x);
  long double ans = 0;
  long i = 0;

  while (i++ < n) {
    ans += d;
    d = std::sin(d);
  }
  return ans;
}

auto pi_series() {
  constexpr double E = 0.0001;
  long double d = 1;
  long double ans = 0;
  long i = 1;

  while (std::abs(d) > E) {
    ans += d;
    d *= -(2 * i - 1) / (double)(2 * i + 1);
    i++;
  }
  return std::tuple(4 * ans, i);
}

long double sin_series(long double x) {
  constexpr double E = 0.0001;
  long double d = x;
  long double ans = 0;
  long i = 1;

  while (std::abs(d) > E) {
    ans += d;
    d *= -x * x / (2 * i) / (2 * i + 1);
    i++;
  }
  return ans;
}

int main() {
  std::cout << pow2_series() << std::endl;
  std::cout << invn_series() << std::endl;
  std::cout << sin_series1(0.5, 10) << std::endl;
  auto [p, n] = pi_series();
  std::cout << p << " " << n << std::endl;

  double x1 = 0, x2 = 2, dx = 0.01;
  std::cout << "Enter left limit: ";
  std::cin >> x1;
  std::cout << "Enter right limit: ";
  std::cin >> x2;
  std::cout << "Enter step value: ";
  std::cin >> dx;
  for (double x = x1; x < x2; x += dx)
    std::cout << sin_series(x) << "\t" << std::sin(x) << std::endl;

  return 0;
}
