#include "mystack.h"
#include "inpost.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//initializes all variables and objects
mystack::mystack()
{
  stackTopPtr = nullptr;
  stackSize = 0;
}

//initializes stack object data members to x object data members
mystack::mystack(const mystack& x)
{
  stackTopPtr = nullptr;

  stackSize = x.stackSize;

  clone(x);
  /*stackSize = x.stackSize;

  if (stackSize == 0)
    Node *stackTopPtr = nullptr;
  else
    Node *stackTopPtr = headPtr;

  for (size_t nodeCnt = 0; nodeCnt < stackSize; ++nodeCnt){
    stackTopPtr = x.stackTopPtr
    stackTopPtr = stackTopPtr->link;
  }*/
  /*for (size_t i = 0; i < stackSize; ++i)//loop to assign all object array values
    stackTopPtr[i] = x.stackTopPtr[i];*/
}

//deconstructor to delete the stack array
mystack::~mystack()
{
  clear();
}

//clone method
void mystack::clone(const mystack& x)
{
   Node* last = nullptr;
   Node* ptr = x.stackTopPtr;
   //Node* new_node = nullptr;

  while (ptr != nullptr){
   //Node* new_node = nullptr;
   //new_node->value = ptr->value;
   Node* new_node = new Node(ptr->value);

   if (last == nullptr)
     stackTopPtr = new_node;
   else
     last->next = new_node;

   last = new_node;
   ptr = ptr->next;
  }
}

//assigns one mystack object to another
mystack& mystack::operator=(const mystack& x)
{
  if (this != &x){
   clear();

   stackSize = x.stackSize;

   clone(x);
  }
  return *this;
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
  while (stackSize != 0){
    pop();
  }
  //stackSize = 0;
}

//simply returns top stack item
const int& mystack::top() const
{
  return(stackTopPtr->value);
  //return (stackArr[stackSize - 1]);
}

//used to push character to top of stack
void mystack::push(int value)
{
  Node* new_node = nullptr;
  new_node->value = value;
  new_node->next = stackTopPtr;

  stackTopPtr = new_node;

  stackSize = stackSize + 1;
}

//simply pops off top character on stack by decrementing stacksize by 1
void mystack::pop()
{
  Node* delete_node = stackTopPtr;
  stackTopPtr = stackTopPtr->next;

  delete delete_node;

  if (stackSize != 0)
    stackSize = stackSize - 1;
}
