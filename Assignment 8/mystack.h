#ifndef MYSTACK_H
  #define MYSTACK_H

#include <cstdlib>

class mystack
{
  private:
        //char *stackArr;//stack array
        //size_t stackCap;
        Node *stackTopPtr;
        size_t stackSize;

  public:
        mystack();
        mystack(const mystack&);
        ~mystack();
        mystack& operator=(const mystack&);
        size_t size() const;
        bool empty() const;
        void clear();
        const int& top() const;//from char to int
        void push(int);//from char to int
        void pop();
        void clone(const mystack&);
};

#endif
