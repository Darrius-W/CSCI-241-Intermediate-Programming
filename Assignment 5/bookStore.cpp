#include "book_store.h"
#include "book.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

book_store::book_store()
{
  validElements = 0;
}

void book_store::print() const
{
  cout << "Book Inventory Listing\n\n";
  cout << "ISBN          Title                                       Price    Qty.\n";

  int inc = 0;

  while(inc < validElements)
  {
     bookStore[inc].print();
     inc++;
  }
}


void book_store::read_book_data(const char* fileRead)
{
  ifstream input;

  input.open(fileRead, ios::binary);

  if (input.fail())
  {
    cout << "File did not open successfully\n";
    exit(-1);
  }
  else
  {
    input.read((char*)this, sizeof(book_store));
    input.close();
  }
}

void book_store::swap(const char* toBeSwapped, const char* og)
{
  const char* temp;
  //book temp;
  temp = og;
  //strcpy(temp, og);
  og  = toBeSwapped;
  //strcpy(og, toBeSwapped);
  toBeSwapped = temp;
  //strcpy(toBeSwapped, temp);
}

void book_store::sortData()
{
  //bubble sort
  int elementsPlaceHolder = validElements;
 // book_store Obj;
  //const char* temp;
  cout << "num of ele: " << validElements << endl;
  do
  {
        int last_swap = 0;
        int i = 1;

        while (i < validElements)
        {
           if (strcmp(bookStore[i - 1].get_isbn(), bookStore[i].get_isbn()) > 0)
           {
                swap(bookStore[i - 1].get_isbn(), bookStore[i].get_isbn());
                //temp = bookStore[i - 1].get_isbn();
                //bookStore[i - 1].get_isbn() = bookStore[i].get_isbn();
                //bookStore[i].get_isbn() = temp;
                last_swap = i;
           }
           i = i + 1;
        }
        validElements = last_swap;

  } while (validElements > 1);

  while (validElements < elementsPlaceHolder)
  {
   cout << "The Isbn: " <<  bookStore[validElements].get_isbn() << endl;
   validElements++;
  }
