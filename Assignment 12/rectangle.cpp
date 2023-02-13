#include <iostream>
#include <cmath>
#include "shape.h"
#include "rectangle.h"
using namespace std;

//constructor
rectangle::rectangle(const string& color, int height, int width) : shape(color){
  this->height = height;
  this->width = width;
}

//print method
void rectangle::print() const{
  shape::print();

  cout << " rectangle, ";
  cout << "height " << height;
  cout << ", width " << width;
  cout << ", area " << get_area();
}

//area method to return area of rectangle
double rectangle::get_area() const{
  return (height * width);
}
