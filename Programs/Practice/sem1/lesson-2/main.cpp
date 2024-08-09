#include <iostream>

void left_triangle() {
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }
}

void center_triangle() {
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < (n + 1) / 2; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << (j >= n / 2 - i && j <= n / 2 + i ? '*' : ' ');
    }
    std::cout << std::endl;
  }
}

void romb() {
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i > n / 2) {
        std::cout << (j >= i - n / 2 && j < 3 * n / 2 - i - 1 ? '*' : ' ');
      } else {
        std::cout << (j >= n / 2 - i && j < n / 2 + i - 1 ? '*' : ' ');
      }
    }
    std::cout << std::endl;
  }
}

void rombs() {
  int n = 0;
  std::cin >> n;
  int r = 0;
  std::cin >> r;

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < r; k++) {
      for (int j = 0; j < n; j++) {
        if (i > n / 2) {
          std::cout << (j >= i - n / 2 && j < 3 * n / 2 - i - 1 ? '*' : ' ');
        } else {
          std::cout << (j >= n / 2 - i && j < n / 2 + i - 1 ? '*' : ' ');
        }
      }
    }
    std::cout << std::endl;
  }
}

void cool_romb() {
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i > n / 2) {
        std::cout << (j % 2 != 0 && j >= i - n / 2 && j < 3 * n / 2 - i - 1 ? '*' : ' ');
      } else {
        std::cout << (j % 2 != 0 && j >= n / 2 - i && j < n / 2 + i - 1 ? '*' : ' ');
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  cool_romb();
}
