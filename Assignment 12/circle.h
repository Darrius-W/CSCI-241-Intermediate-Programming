
#ifndef CIRCLE_H
  #define CIRCLE_H

#include "shape.h"
#include <iostream>
#include <string>
using namespace std;

class circle : public shape{

  private:

        int radius;

  public:

        circle(const string&, int);
        virtual void print() const;
        virtual double get_area() const;
};

#endif
