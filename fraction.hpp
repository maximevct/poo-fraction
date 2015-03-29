#include <iostream>

class fraction {
private:
  int _denom;
  int _num;
public:
  fraction(int n, int d) {
    _num = n;
    _denom = d;
  }
  ~fraction() {}

  const int getNumerator() { return _num; }
  const int getDenominator() { return _denom; }

  fraction operator~() const {
    return fraction(_denom, _num);
  }

  fraction operator+(fraction f) const {
    return fraction(_num * f.getDenominator() + f.getNumerator() * _denom,
		    _denom * f.getDenominator());
  }
  fraction operator+(int val) const {
    return *this + fraction(val, 1);
  }
  friend fraction operator+(int val, const fraction &f) { return f + val; }

  fraction operator-(int val) const {
    return fraction(_num - val, _denom - val);
  }
  fraction operator-(fraction f) const {
    return fraction(_num - f.getNumerator(), _denom - f.getDenominator());
  }
  friend fraction operator-(int val, const fraction &f) { return f - val; }

  fraction operator*(int val) const {
    return fraction(_num * val, _denom * val);
  }
  fraction operator*(fraction f) const {
    return fraction(_num * f.getNumerator(), _denom * f.getDenominator());
  }
  friend fraction operator*(int val, const fraction &f) { return f * val; }

  fraction operator/(int val) const {
    return fraction(_num / val, _denom / val);
  }
  fraction operator/(fraction f) const {
    return fraction(_num / f.getNumerator(), _denom / f.getDenominator());
  }
  friend fraction operator/(int val, const fraction &f) { return f / val; }


  friend std::ostream &operator<<(std::ostream &os, const fraction &f) {
    os << f._num << "/" << f._denom;
    return os;
  }
};
