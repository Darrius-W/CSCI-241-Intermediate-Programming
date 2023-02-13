#include "book.h"
#include "book_store.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
  book_store bookStoreObj;

  //bookStoreObj.print();

  bookStoreObj.read_book_data("bookdata");

  bookStoreObj.sortData();

  bookStoreObj.print();
  /*int books;
  book book_Obj;

  books = book_Obj.fulfill_order(-8);

  book_Obj.print();
  book_Obj.print();
  cout << "shipped is " << books << endl;
  books = book_Obj.fulfill_order(8);
  book_Obj.print();
  cout << "shipped is " << books << endl;*/

  return 0;
}
