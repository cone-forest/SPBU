#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

constexpr double eps1 = 1e-6 / 0.18;
constexpr double eps2 = 1e-6 / 2.7;
constexpr double eps3 = 1e-6 / 3.0;

double custom_sin(double x, double accuracy) {
  double term = x;
  double sum = term;

  for (int i = 1; std::abs(term) >= accuracy; ++i) {
    term = (-1) * term * x * x / ((2 * i) * (2 * i + 1));
    sum += term;
  }

  return sum;
}

double custom_cosh(double x, double accuracy) {
  double term = 1.0;
  double sum = term;

  for (int i = 1; std::abs(term) >= accuracy; ++i) {
    term = term * x * x / ((2 * i) * (2 * i - 1));
    sum += term;
  }

  return sum;
}

double custom_sqrt(double x, double accuracy) {
  double z = std::max(x, 1.0);

  while (std::abs(z * z - x) >= accuracy) {
    z = (z + x / z) / 2;
  }

  return z;
}

void calculate(double start, double end, double step) {
  std::cout << std::setprecision(10);

  for (double x = start; x <= end + step / 2; x += step) {
    double ch_arg = x * x + 0.3 / (1.0 + x);
    double sin_arg = (1.0 + x) / (0.6 * x);

    double my_ch = custom_cosh(ch_arg, eps2);
    double std_ch = std::cosh(ch_arg);

    double my_sin = custom_sin(sin_arg, eps1);
    double std_sin = std::sin(sin_arg);

    double my_calc = my_ch * my_sin;
    double std_calc = std_ch * std_sin;

    double err = std::abs(my_calc - std_calc);

    std::cout << "x = " << std::setw(4) << x << " | my_calc = " << std::setw(12)
      << my_calc << " | std_calc = " << std::setw(12) << std_calc
      << " | error = " << std::setw(12) << err << "\n";
  }
}

int main() {
  calculate(0.2, 0.3, 0.01);
  return 0;
}
