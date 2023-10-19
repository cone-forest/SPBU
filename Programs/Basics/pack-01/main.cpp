#include <chrono>
#include <iostream>
#include <execution>
#include <numeric>
#include <ostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <string>

inline static const int C = 1e2;

template<typename F, typename... Args>
auto timer(F f, Args... args) {
  auto a = std::chrono::high_resolution_clock::now();
  f(args...);
  auto b = std::chrono::high_resolution_clock::now();

  return std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count();
}

std::string reverse_words(std::string str)
{
  for (auto c1 = str.begin(); c1 < str.end(); ++c1) {
    // find iterator to first character of a word
    while (*c1 == ' ')
      ++c1;

    // find iterator to last character of a word
    auto c2 = c1;
    while (c2 < str.end() && *c2 != ' ')
      ++c2;

    // reverse word inplace
    // unsequenced execution utilizes simd instructions
    std::reverse(std::execution::unseq, c1, c2);

    c1 = c2;
  }

  return str;
}

bool narcissistic( int value ){
  std::string value_str = std::to_string(value);
  std::cout << value_str; 

  size_t len = value_str.size();
  return value == std::reduce(value_str.begin(), value_str.end(), 0, [len](auto s, auto e) -> auto {return s + std::pow(e - '0', len);});
}

int persistence(long long n){
  if (n < 10)
    return 0;
  
  int cnt = 0;
  std::string n_str {};
  long long s = n;
  
  do {
    n_str = std::to_string(s);
    s = std::transform_reduce(n_str.begin(), n_str.end(), 1, std::multiplies{}, [](auto val){return val - '0';});

    std::cout
      << s << std::endl
      ;
    cnt++;
  } while (s > 9);
  
  return cnt;
}

unsigned short int expressionsMatter (unsigned short int a , unsigned short int b , unsigned short int c)
{
  return std::max({
    a + b + c,
    a + b * c,
    a * b + c,
    a * b * c,
    (a + b) * c,
    a * (b + c)}
  );
}

std::string DNAtoRNA(std::string dna){
  std::string ans = dna;
  std::replace_copy(std::execution::par_unseq, dna.begin(), dna.end(), ans.begin(), ' ', ' ');
  return std::move(ans);
}

#include <cctype>

std::string abbrevName(std::string name)
{
  return {static_cast<char>(std::toupper(name[0])), '.', static_cast<char>(std::toupper(*std::next(std::find(name.begin(), name.end(), ' '))))};
}

int main() {
  std::string s = ";aflksdjj;        lksdfaj;        ksadjk; ";
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  std::cout << s << std::endl;
  // auto benchmark = [&](auto f){
  //   for (int i = 0; i < C; i++)
  //     for (int j = 0; j < C; j++)
  //       for (int k = 0; k < C; k++)
  //         for (int l = 0; l < C; l++)
  //           f("GCAT");
  // };

  // std::cout << timer(benchmark, DNAtoRNA) << std::endl;

  return 0;
}
