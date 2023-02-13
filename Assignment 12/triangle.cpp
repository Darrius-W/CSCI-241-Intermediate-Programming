#include <iostream>
#include <cmath>
#include "shape.h"
#include "triangle.h"
using namespace std;

//constructor
triangle::triangle(const string& color, int height, int base) : shape(color){
  this->height = height;
  this->base = base;
}

//print method
void triangle::print() const{
  shape::print();

  cout << " triangle, ";
  cout << "height " << height;
  cout << ", base " << base;
  cout << ", area " << get_area();
}

//area method to return area of triangle
double triangle::get_area() const{
  return (0.5 * (base * height));
}