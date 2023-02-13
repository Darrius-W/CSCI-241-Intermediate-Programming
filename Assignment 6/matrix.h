#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;
class matrix
{
  friend ostream &operator<<(ostream &, const matrix &);
  friend matrix operator*(const int &, const matrix &);

public:
  matrix();          // constructor
  matrix(int[2][2]); // alternate constructor
  int determinant() const;
  matrix operator+(const matrix &) const;
  matrix operator*(const int &) const;
  matrix operator*(const matrix &) const;
  bool operator==(const matrix &) const;
  bool operator!=(const matrix &) const;

private:
  int matrixArr[2][2];
};

#endif
