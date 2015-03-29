#include <iostream>

class fraction {
private:
  int _denom;
  int _num;

  int abs(int a) {
    if (a < 0)
      return -a;
  }
  
  void negative() {
    -abs(_num);
    abs(_denom);
  }

  void positive() {
    negative();
    -_num;
  }

  int PGCD(int a, int b) {
    return (b == 0) ? a : PGCD(b, a % b);
  }

  void reduce() {
    int pgcd = PGCD(_num, _denom);
    _num /= pgcd;
    _denom /= pgcd;
  }
public:
  fraction(int n, int d) {
    _num = n;
    _denom = d;
    ((_num < 0 && _denom < 0)
     || (_num > 0 && _denom > 0)) ? positive() : negative();
    reduce();
  }
  ~fraction() {}

  const int getNumerator() { return _num; }
  const int getDenominator() { return _denom; }

  /** UNARY **/
  fraction operator~() const {
    return fraction(_denom, _num);
  }

  fraction operator-() const {
    return fraction(-_num, _denom);
  }

  /** ADDITION **/
  fraction operator+(fraction f) const {
    return fraction(_num * f.getDenominator() + f.getNumerator() * _denom,
		    _denom * f.getDenominator());
  }
  fraction operator+(int val) const {
    return *this + fraction(val, 1);
  }
  friend fraction operator+(int val, const fraction &f) {
    return f + val;
  }

  /** SUBSTRACTION */
  fraction operator-(fraction f) const {
    return *this + (-f);
  }
  fraction operator-(int val) const {
    return *this - fraction(val, 1);
  }
  friend fraction operator-(int val, const fraction &f) {
    return val + (-f);
  }

  /** MULTIPLICATION **/
  fraction operator*(fraction f) const {
    return fraction(_num * f.getNumerator(), _denom * f.getDenominator());
  }
  fraction operator*(int val) const {
    return *this * fraction(val, 1);
  }
  friend fraction operator*(int val, const fraction &f) {
    return f * fraction(val, 1);
  }

  /** DIVISION **/
  fraction operator/(fraction f) const {
    return *this * (~f);
  }
  fraction operator/(int val) const {
    return *this / fraction(val, 1);
  }
  friend fraction operator/(int val, const fraction &f) { return val * (~f); }


  friend std::ostream &operator<<(std::ostream &os, const fraction &f) {
    os << f._num << "/" << f._denom;
    return os;
  }
};
