
#include <iostream>
#include <cmath>
#include "shape.h"
#include "circle.h"
using namespace std;

#define PI 3.141592

//constructor
circle::circle(const string& color, int radius) : shape(color){
  this->radius = radius;
}

//print method
void circle::print() const{
  shape::print();

  cout << " circle, ";
  cout << "radius " << radius;
  cout << ", area " << get_area();
}

//area method to return area of circle
double circle::get_area() const{
  return (PI * (radius * radius));
}
