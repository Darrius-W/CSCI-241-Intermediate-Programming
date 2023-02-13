#ifndef MYLIST_H
 #define MYLIST_H

#include <iostream>
#include <stdexcept>

//header file <stdexcept> for empty method

// Forward declaration of the mylist template class
template <class T>
class mylist;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);

template <class T>
struct node
{
  T value;
  node<T>* prev;
  node<T>* next;

  node (const T& initVal = T(), node<T>* initPrev = 0, node<T>* initNext = 0){
    this->value = initVal;
    this->prev = initPrev;
    this->next = initNext;
  }

};

template <class T>
class mylist
{
    // friend declaration for the template function - note the special syntax
  friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);

  private:
        node<T>* frontNode;
        node<T>* backNode;
        size_t totalEle;

  public:
        mylist();
        void clear();
        void pop_front();
        ~mylist();
        bool empty() const;
        size_t size() const;
        void push_back(const T&);
        void push_front(const T&);
        const T& front() const;
        T& front();
        const T& back() const;
        T& back();
        void pop_back();
        mylist(const mylist<T>&);
        mylist<T>& operator=(const mylist<T>&);
        bool operator==(const mylist<T>&) const;
        bool operator<(const mylist<T>&) const;
};

// Function definitions for the mylist class

//default constructor
//setting nodes and size_t data member to initial state
template <class T>
mylist<T>::mylist(){
  frontNode = nullptr;
  backNode = nullptr;
  totalEle = 0;
}

//clear method
template <class T>
void mylist<T>::clear(){
  while (totalEle != 0){
    pop_front();
  }

  delete frontNode;
  delete backNode;

  totalEle = 0;
}

//pop front method
template <class T>
void mylist<T>::pop_front(){
  if (empty())
    throw std::underflow_error("underflow exception on call to pop_front()");

  else{
    node<T>* delNode = frontNode;
    frontNode = delNode->next;

    if(frontNode != nullptr)
      frontNode->prev = nullptr;

    else
      backNode = nullptr;

    delete delNode;
    totalEle--;
  }
}

//deconstructor
template <class T>
mylist<T>::~mylist(){
  clear();
}

//empty method
template <class T>
bool mylist<T>::empty() const{
  if (totalEle == 0)
    return true;

  else
    return false;
}

//overloaded output operator
template <class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& obj){
  node<T>* currPtr = obj.frontNode;

  for (size_t i = 0; i < obj.totalEle; i++){

    os << currPtr->value << " ";
    currPtr = currPtr->next;
  }
  return os;
}

//size method
template <class T>
size_t mylist<T>::size() const{
  return totalEle;
}

//push back method
template <class T>
void mylist<T>::push_back(const T& value){
  node<T>* newNode = new node<T>(value);
  newNode->prev = backNode;

  if (backNode != nullptr)
    backNode->next = newNode;

  else
    frontNode = newNode;

  backNode = newNode;
  totalEle++;
}

//push front method
template <class T>
void mylist<T>::push_front(const T& value){
  node<T>* newNode = new node<T>(value);
  newNode->next = frontNode;

  if (frontNode != nullptr)
    frontNode->prev = newNode;

  else
    backNode = newNode;

  frontNode = newNode;
  totalEle++;
}

//front method
template <class T>
const T& mylist<T>::front() const{
  if (empty())
    throw std::underflow_error("underflow exception on call to front()");

  else
    return frontNode->value;
}

//2nd front method
template <class T>
T& mylist<T>::front(){
  if (empty())
    throw std::underflow_error("underflow exception on call to front()");

  else
    return frontNode->value;
}

//back method
template <class T>
const T& mylist<T>::back() const{
  if (empty())
    throw std::underflow_error("underflow exception on call to back()");

  else
    return backNode->value;
}

//2nd back method
template <class T>
T& mylist<T>::back(){
  if (empty())
    throw std::underflow_error("underflow exception on call to back()");

  else
    return backNode->value;
}

//pop back method
template <class T>
void mylist<T>::pop_back(){
  if (empty())
    throw std::underflow_error("underflow exception on call to pop_back()");

  else{
    node<T>* delNode = backNode;
    backNode = delNode->prev;

    if (backNode != nullptr)
      backNode->next = nullptr;

    else
      frontNode = nullptr;

    delete delNode;
    totalEle--;
  }
}

//copy constructor
template <class T>
mylist<T>::mylist(const mylist<T>& x){
    totalEle = 0;
    node<T>* ptr = x.frontNode;

    while (ptr != nullptr){

      push_back(ptr->value);
      ptr = ptr->next;
    }

  return;
}

//overloaded assignment operator
template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x){
  if (this == &x)
    return *this;

  if (!empty())
    clear();

  node<T>* ptr = x.frontNode;

  while (ptr != nullptr){

    push_back(ptr->value);
    ptr = ptr->next;
  }

  return *this;
}

//overloaded equality operator
template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const{
  if (size() != rhs.size())
    return false;

  node<T>* ptr1 = frontNode;
  node<T>* ptr2 = rhs.frontNode;

  while (ptr1 && ptr2){

    if (ptr1->value != ptr2->value)
      return false;

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return true;
}

//overloaded less than operator
template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const{
  node<T>* ptr1 = frontNode;
  node<T>* ptr2 = rhs.frontNode;

  while (ptr1 != nullptr && ptr2 != nullptr){

    if (ptr1->value < ptr2->value)
      return true;

    else if (ptr1->value > ptr2->value)
      return false;

    else{
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }

  if (ptr1 == nullptr && ptr2 != nullptr)
    return true;

  else
    return false;
}
#endif
