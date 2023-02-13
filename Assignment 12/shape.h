
#ifndef SHAPE_H
 #define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

//base class
class shape{

  private:

        string color;

  public:

        shape(const string&);
        virtual ~shape();//virtual destructor
        virtual void print() const;
        virtual double get_area() const = 0;//pure virtual method double get_area
};
#endif
