#include "mystack.h"
#include "inpost.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//initializes all variables and objects
mystack::mystack()
{
  stackArr = nullptr;
  stackSize = 0;
  stackCap = 0;
}

//initializes stack object data members to x object data members
mystack::mystack(const mystack& x)
{
  stackSize = x.stackSize;
  stackCap = x.stackCap;

  if (stackCap > 0)
    stackArr = new char[stackCap];
  else
    stackArr = nullptr;

  for (size_t i = 0; i < stackSize; ++i)//loop to assign all object array values
    stackArr[i] = x.stackArr[i];
}

//deconstructor to delete the stack array
mystack::~mystack()
{
  delete [] stackArr;
}

//assigns one mystack object to another
mystack& mystack::operator=(const mystack& x)
{
  if (this != &x)
  {
    delete [] stackArr;

    stackCap = x.stackCap;
    stackSize = x.stackSize;

    if (stackCap > 0)
      stackArr = new char[stackCap];
    else
      stackArr = nullptr;

    for (size_t i = 0; i < stackSize; ++i)
      stackArr[i] = x.stackArr[i];
  }

  return *this;
}

//simply to return stack capacity
size_t mystack::capacity() const
{
  return stackCap;
}

//simply to return stack size
size_t mystack::size() const
{
  return stackSize;
}

//checks if stack is empty and returns true/false value
bool mystack::empty() const
{
  if (stackSize == 0)
    return true;
  else
    return false;
}

//simply sets stack size to 0
void mystack::clear()
{
  stackSize = 0;
}

//modifys stack capacity without altering stack size
void mystack::reserve(size_t n)
{
  if (n < stackSize || n == stackCap)
    return;

  stackCap = n;

  char *tempArr;
  tempArr = new char[stackCap];

  for (size_t i = 0; i < stackSize; i++)
    tempArr[i] = stackArr[i];


  delete [] stackArr;

  stackArr = tempArr;
}

//simply returns top stack item
const char& mystack::top() const
{
  return (stackArr[stackSize - 1]);
}

//used to push character to top of stack
void mystack::push(char value)
{
  if (stackSize == stackCap)
  {
    if (stackCap == 0)
       reserve(stackCap + 1);//if capacity is 0 it get incremented by 1
    else
       reserve(stackCap * 2);
  }

  stackArr[stackSize] = value;
  stackSize = stackSize + 1;
}

//simply pops off top character on stack by decrementing stacksize by 1
void mystack::pop()
{
  stackSize = stackSize - 1;
}
