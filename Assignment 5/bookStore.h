#ifndef BOOK_STORE_H
 #define BOOK_STORE_H

#include "book.h"

class book_store
{
  private:

        book bookStore[30];
        int validElements;

  public:

        book_store();
        void read_book_data(const char*);
        void process_orders(const char*);
        void print() const;
        void swap(const char*, const char*);
        void sortData();
};

#endif
