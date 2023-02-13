#ifndef RECTANGLE_H
  #define RECTANGLE_H

#include <iostream>
#include "shape.h"
#include <string>
using namespace std;

class rectangle : public shape{

  private:

        int height;
        int width;

  public:

        rectangle(const string&, int, int);
        virtual void print() const;
        virtual double get_area() const;
};

#endif
