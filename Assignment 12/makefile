
#***************************************************************
#
#  makefile
#  CSCI 241 Assignment 12
#  Due: Dec 2, 2020
#  Created by Darrius White (z1900146).
#
#***************************************************************

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

#Rule to link object code files to create executable file
assign12: assign12.o shape.o circle.o rectangle.o triangle.o
        $(CXX) $(CXXFLAGS) -o assign12 $^

#Rules to compile source code file to object code
assign12.o: assign12.cpp circle.h shape.h rectangle.h triangle.h
shape.o: shape.cpp shape.h
circle.o: circle.cpp circle.h
rectangle.o: rectangle.cpp rectangle.h
triangle.o: triangle.cpp triangle.h

circle.h: shape.h
rectangle.h: shape.h
triangle.h: shape.h

#Pseudo-target to remove object code and executable files
clean:
        rm -f assign12 *.o
