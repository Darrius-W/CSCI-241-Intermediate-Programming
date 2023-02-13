#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
using namespace std;

int main(){
  shape* baseArr[6];//shape object pointers

  //assignment of different shapes
  baseArr[0] = new circle("green", 10);
  baseArr[4] = new circle("orange", 5);
  baseArr[1] = new rectangle("red", 8, 6);
  baseArr[5] = new rectangle("blue", 3, 7);
  baseArr[2] = new triangle("yellow", 8, 4);
  baseArr[3] = new triangle("black", 4, 10);

  cout << "Printing all shapes...\n" << endl;

  //loop through all array pointers
  for (int i = 0; i < 6; i++){
    baseArr[i]->print();
    cout << endl;
  }

  cout << endl;
  cout << "Printing only circles...\n" << endl;

  //loop through array of pointers calling print for each circle object
  for (int j = 0; j < 6; j++){
    circle* cirPtr = dynamic_cast<circle *>(baseArr[j]);

    if (cirPtr != 0){
      baseArr[j]->print();
      cout << endl;
    }
  }

  //deleteing array
  for (int k = 0; k < 6; k++){
    delete baseArr[k];
  }

  return 0;
}