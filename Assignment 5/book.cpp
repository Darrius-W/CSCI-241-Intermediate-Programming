#include "book.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

book::book()
{
  strcpy(isbn, "None");
  strcpy(title, "None");
  quantity_in_stock = 0;
  price = 0;
}

const char* book::get_isbn()
{
  return isbn;
}

const double book::get_price()
{
  return price;
}

int book::fulfill_order(int orderQuantity)
{
  if (orderQuantity < 0)
    orderQuantity = 0;

  else if (orderQuantity <= quantity_in_stock)
    quantity_in_stock = quantity_in_stock - orderQuantity;

  else if (orderQuantity > quantity_in_stock)
  {
    orderQuantity = quantity_in_stock;
    quantity_in_stock = 0;
  }

  return orderQuantity;
}

void book::print() const
{
  cout << setw(14) << left << isbn;
  cout << setw(44) << left << title;
  cout << fixed;
  cout << setprecision(2) << setw(5) << right << price;
  cout << setw(6) << right << quantity_in_stock << endl;
}
