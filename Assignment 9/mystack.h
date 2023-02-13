#ifndef MYSTACK_H
  #define MYSTACK_H

#include <cstdlib>

class mystack
{
  private:
        char *stackArr;//stack array
        size_t stackCap;
        size_t stackSize;

  public:
        mystack();
        mystack(const mystack&);
        ~mystack();
        mystack& operator=(const mystack&);
        size_t capacity() const;
        size_t size() const;
        bool empty() const;
        void clear();
        void reserve(size_t);
        const char& top() const;
        void push(char);
        void pop();
};

#endif
