# poo-fraction

## Overloaded opérators
### UNARY
```c++
  fraction operator~() const;
  fraction operator-() const;
  fraction operator+() const;
```

### ADDITION
```c++
  fraction operator+(fraction) const;
  fraction operator+(int) const;
  fraction &operator+=(int);
  friend fraction operator+(int, const fraction &);
```

### SUBSTRACTION
```c++
  fraction operator-(fraction) const;
  fraction operator-(int) const;
  fraction &operator-=(int);
  friend fraction operator-(int, const fraction &);
```

### MULTIPLICATION
```c++
  fraction operator*(fraction) const;
  fraction operator*(int) const;
  fraction &operator*=(int);
  friend fraction operator*(int, const fraction &);
```

### DIVISION
```c++
  fraction operator/(fraction) const;
  fraction operator/(int) const;
  fraction &operator/=(int);
  friend fraction operator/(int, const fraction &);
```

### STREAM
```c++
  friend std::ostream &operator<<(std::ostream &, const fraction &);
```

## Author
Maxime Vincent <twiggeek@gmail.com>
