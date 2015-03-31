#include <iostream>

#include "fraction.hpp"

int main() {
  fraction a(4,3);
  fraction b(5,4);

  std::cout << "---------SUJET-----------" << std::endl;
  std::cout
    << "a=" << a << std::endl
    << "b=" << b << std::endl
    << "~a=" << ~a << std::endl
    << "~b=" << ~b << std::endl
    << "-a=" << -a << std::endl
    << "-b=" << -b << std::endl
    << "+a=" << +a << std::endl
    << "+b=" << +b << std::endl
    << "4+a=" << 4+a << std::endl
    << "a+4=" << a+4 << std::endl
    << "4-a=" << 4-a << std::endl
    << "a-4=" << a-4 << std::endl
    << "a+b=" << a+b << std::endl
    << "a-b=" << a-b << std::endl
    << "a*b=" << a*b << std::endl
    << "a*3=" << a*3 << std::endl
    << "11*a=" << 11*a << std::endl
    << "a/b=" << a/b << std::endl
    << "7/a=" << 7/a << std::endl
    << "a/9=" << a/9 << std::endl
  ;

  std::cout << "---------REDUCTION-----------" << std::endl;
  // 3/7
  std::cout << fraction(3,4)*fraction(4,5)*fraction(5,6)*fraction(6,7) << std::endl;

  std::cout << "---------NEGATIVE-----------" << std::endl;
  std::cout
    << "fraction(-2, 3)=" << fraction(-2, 3) << std::endl
    << "fraction(2, -3)=" << fraction(2, -3) << std::endl
    << "fraction(-2,-3)=" << fraction(-2,-3) << std::endl
    << "fraction( 2, 3)=" << fraction( 2, 3) << std::endl
    << "+fraction(-2, 3)=" << fraction(-2, 3) << std::endl
    << "+fraction(2, -3)=" << fraction(2, -3) << std::endl
    << "+fraction(-2,-3)=" << fraction(-2,-3) << std::endl
    << "+fraction( 2, 3)=" << fraction( 2, 3) << std::endl
  ;

  std::cout << "---------0/x-----------" << std::endl;
  std::cout
    << "fraction(0, 1)=" << fraction(0, 1) << std::endl
    << "fraction(0, 5)=" << fraction(0, 5) << std::endl
  ;

  std::cout << "---------x/0-----------" << std::endl;
  try {
    fraction(1, 0);
  } catch (...) {
    std::cout << "1/0" << std::endl;
  }

  std::cout << "---------DIVISION_BY_ZERO-----------" << std::endl;
  try {
    fraction(1, 0) / 0;
  } catch (...) {
    std::cout << "1/0 / 0" << std::endl;
  }
  try {
    fraction(1, 0) / fraction(1, 0);
  } catch (...) {
    std::cout << "1/0 / 1/0" << std::endl;
  }
  try {
    0 / fraction(1, 0);
  } catch (...) {
    std::cout << "0 / 1/0" << std::endl;
  }
  return 0;
}
