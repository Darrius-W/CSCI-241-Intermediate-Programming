#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
        int printedIndex = 0;
        int increment = 0;
        int element = 0;
        int count = 1;
        int insertionSortArr[1000];
        bool status = true;
        int temp;

        //Gets each element in file
        while (cin >> element)
        {
           insertionSortArr[increment] = element;
           increment++;
        }

        //Outer loop  after each iteration sorts one element
        //at a time depending on size
        for (int i = 0; i < increment; i++)
        {

           for (int ii = 0; ii < increment; ii++)
           {

              if (ii > 0)
              {
                 temp = ii - 1;//Temporary index value to compare elements

                 do
                 {

                    if (insertionSortArr[ii] < insertionSortArr[temp])
                    {
                        swap(insertionSortArr[temp], insertionSortArr[ii]);
                        status = true;
                    }

                    else
                    {
                        status = false;
                    }

                    }while (status != false);
                 }
            }
        }


        //Prints all elements to screen in new sorted order
        while (printedIndex < increment)
        {
           cout << setw(8) << insertionSortArr[printedIndex] << '\t';

           if (count % 8 == 0)//Creates newline after 8 elements outputted
           {
              cout << '\n';
           }

           printedIndex++;
           count++;
        }

        cout << endl;

        return 0;
}

