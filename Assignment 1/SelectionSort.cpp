#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
        int minimum, minimumIndex, elements;
        int selectionSortArr[1000];
        int printedIndex = 0;
        int increment = 0;
        int count = 1;

        //Gets all elements from file
        while (cin >> elements)
        {
           selectionSortArr[increment] = elements;
           increment++;
        }


        //Outer loop permanently sorts smallest element
        //each iteration
        for (int i = 0; i < increment; i++)
        {

           for (int ii = i; ii < increment; ii++)
           {

              if (ii == i)
              {
                 minimum = selectionSortArr[ii];//Sets default minimum element
                 minimumIndex = ii;
              }

              if (minimum >= selectionSortArr[ii])//compares current smallest element to others
              {
                 minimum = selectionSortArr[ii];
                 minimumIndex = ii;
              }
           }

           swap(selectionSortArr[i], selectionSortArr[minimumIndex]);
        }


        //Prints elements to screen
        while (printedIndex < increment)
        {
           cout << setw(8) << selectionSortArr[printedIndex] << '\t';

           if (count % 8 == 0)//Creates newline after every 8 elements printed
           {
              cout << '\n';
           }

           printedIndex++;
           count++;
        }

        cout << endl;

        return 0;
}

