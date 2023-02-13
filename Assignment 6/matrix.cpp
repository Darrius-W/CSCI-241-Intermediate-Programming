#include "matrix.h"
#include <iostream>
using namespace std;

//constructor to initializes all matrix array elements
matrix::matrix()
{
  matrixArr[0][0] = 1;
  matrixArr[0][1] = 0;
  matrixArr[1][0] = 0;
  matrixArr[1][1] = 1;
}

//friend function for Test one
ostream& operator<<(ostream& theOstream, const matrix& osMatrix)
{
  theOstream << "[[" << osMatrix.matrixArr[0][0] << ", " << osMatrix.matrixArr[0][1] << "], ["//Tests the initialized elements in matrix array
             << osMatrix.matrixArr[1][0] << ", " <<  osMatrix.matrixArr[1][1] << "]]";

  return theOstream;
}

//Alternate constructor for Test two
matrix::matrix(int argMatrixArr[2][2])
{
  for (int i = 0; i < 2; i++)
     for (int j = 0; j < 2; j++)
        matrixArr[i][j] = argMatrixArr[i][j];//Assigns values from arguement array to the class private array
}

//Method for Test three
int matrix::determinant() const
{
  int det;//Integer to hold result of matrix arithmetic

  det = (matrixArr[0][0] * matrixArr[1][1]) - (matrixArr[0][1] * matrixArr[1][0]);//Expression of matrices gets stored in det

  return det;
}

//+ method overload for Test four
matrix matrix::operator+(const matrix& rightMatrix) const
{
  matrix sum;//Object to hold matrix sum

  for (int i = 0; i < 2; i++)
     for (int j = 0; j < 2; j++)
        sum.matrixArr[i][j] = this->matrixArr[i][j] + rightMatrix.matrixArr[i][j];//Adds two matrices

  return sum;
}

// * method overload for Test five - matrix multiplied by 2
matrix matrix::operator*(const int& multMatrix) const
{
  matrix scalarProduct;//Object to hold the scalar multiplication result

  for (int i =0; i < 2; i++)
    for (int j = 0; j < 2; j++)
        scalarProduct.matrixArr[i][j] = this->matrixArr[i][j] * multMatrix;//Multiplies matrix to arguement integer

  return scalarProduct;
}

// * method overload for Test five - matrix multiplied by 4
matrix operator*(const int& multiply, const matrix& rightArr)
{
  matrix scalarProduct;//Object holds scalar multiplication result

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
        scalarProduct.matrixArr[i][j] = multiply * rightArr.matrixArr[i][j];//Multiply matrix to arguement integer

  return scalarProduct;
}

// * method overload for Test six
matrix matrix::operator*(const matrix& rightArr) const
{
  matrix product;//holds result of matrix expressions

  //multiplies and adds together two matrices
  product.matrixArr[0][0] = (this->matrixArr[0][0] * rightArr.matrixArr[0][0]) + (this->matrixArr[0][1] * rightArr.matrixArr[1][0]);
  product.matrixArr[0][1] = (this->matrixArr[0][0] * rightArr.matrixArr[0][1]) + (this->matrixArr[0][1] * rightArr.matrixArr[1][1]);
  product.matrixArr[1][0] = (this->matrixArr[1][0] * rightArr.matrixArr[0][0]) + (this->matrixArr[1][1] * rightArr.matrixArr[1][0]);
  product.matrixArr[1][1] = (this->matrixArr[1][0] * rightArr.matrixArr[0][1]) + (this->matrixArr[1][1] * rightArr.matrixArr[1][1]);

  return product;
}

// == method overload for Test seven
bool matrix::operator==(const matrix& rightArr) const
{
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
        if(this->matrixArr[i][j] != rightArr.matrixArr[i][j])//Condition statement tests if matrices are not equal
           return false;//returns false if matrices are found not to be equal
    }

  return true;
}

// !=  method overload for Test seven
bool matrix::operator!=(const matrix& rightArr) const
{
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
        if(this->matrixArr[i][j] == rightArr.matrixArr[i][j])//Condition statement tests if matrices are equal
           return false;//returns false if matrices are found to be equal
    }

  return true;
}
