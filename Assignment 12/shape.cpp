
#include <iostream>
#include "circle.h"
#include "shape.h"
using namespace std;

//constructor
shape::shape(const string& strData){
  color = strData;
}

//destructor
shape::~shape(){
}

//print method
void shape::print() const{
  cout << color;
}
