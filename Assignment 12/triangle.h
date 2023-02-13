#ifndef TRIANGLE_H
  #define TRIANGLE_H

#include <iostream>
#include "shape.h"
#include <string>
using namespace std;

class triangle : public shape{

  private:

        int height;
        int base;

  public:

        triangle(const string&, int, int);
        virtual void print() const;
        virtual double get_area() const;
};

#endif
