#include <iostream>
#include <stdexcept>

class fraction {
private:
  int _denom;
  int _num;

  int abs(int a) {
    return (a < 0) ? -a : a;
  }

  void negative() {
    _num = -abs(_num);
    _denom = abs(_denom);
  }

  void positive() {
    negative();
    _num = -_num;
  }

  int PGCD(int a, int b) {
    return (b == 0) ? a : PGCD(b, a % b);
  }

  void reduce() {
    int pgcd = PGCD(abs(_num), abs(_denom));
    _num /= pgcd;
    _denom /= pgcd;
  }
public:
  fraction(int n, int d) {
    if (d == 0)
      throw new std::logic_error("Divided by zero");
    _num = n;
    _denom = d;
    reduce();
    ((_num < 0 && _denom < 0)
     || (_num > 0 && _denom > 0)) ? positive() : negative();
  }
  fraction(const fraction &f) {
    _num = f.getNumerator();
    _denom = f.getDenominator();
 }
  fraction &operator=(const fraction &f) {
    if (&f != this) {
      _num = f.getNumerator();
      _denom = f.getDenominator();
    }
    return *this;
  }
  ~fraction() {}

  const int getNumerator()   const { return _num; }
  const int getDenominator() const { return _denom; }

  /** UNARY **/
  fraction operator~() const {
    return fraction(_denom, _num);
  }

  fraction operator-() const {
    return fraction(-_num, _denom);
  }
  fraction operator+() const {
    return fraction(_num, _denom);
  }

  /** ADDITION **/
  fraction operator+(fraction f) const {
    return fraction(_num * f.getDenominator() + f.getNumerator() * _denom,
		              _denom * f.getDenominator());
  }
  fraction operator+(int val) const {
    return *this + fraction(val, 1);
  }
  fraction &operator+=(int val) {
    *this = *this + val;
    return *this;
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
  fraction &operator-=(int val) {
    *this = *this - val;
    return *this;
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
  fraction &operator*=(int val) {
    *this = *this * val;
    return *this;
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
  fraction &operator/=(int val) {
    *this = *this / val;
    return *this;
  }
  friend fraction operator/(int val, const fraction &f) {
    return val * (~f);
  }

  /** STREAM **/
  friend std::ostream &operator<<(std::ostream &os, const fraction &f) {
    os << f._num;
    if (f._denom != 1)
      os << "/" << f._denom;
    return os;
  }
};
