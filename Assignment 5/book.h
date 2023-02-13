#ifndef BOOK_H
 #define BOOK_H

class book
{
  private:

        char isbn[11];
        char title[41];
        double price;
        int quantity_in_stock;

  public:

        book();
        const char* get_isbn();
        const double get_price();
        int fulfill_order(int);
        void print()const;
};

#endif
