#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int bubbleSortArray[1000];
  int individualElement;
  int increment = 0;
  int printedIndex = 0;
  int count = 1;

  // Loop to obtain all elements in file
  while (cin >> individualElement)
  {
    bubbleSortArray[increment] = individualElement;
    increment++; // Will increment to total elements
  }

  // Permanently sorts element(s) each iteration
  // based on size.
  for (int ii = 0; ii < increment; ii++)
  {

    for (int i = 0; i < increment; i++) // Inner loop to compare each element
    {

      if (i < increment - 1)
      {

        if (bubbleSortArray[i] > bubbleSortArray[i + 1])
        {
          swap(bubbleSortArray[i], bubbleSortArray[i + 1]);
        }
      }
    }
  }

  // Printing sorted elements to screen
  while (printedIndex < increment)
  {
    cout << setw(8) << bubbleSortArray[printedIndex] << '\t';

    if (count % 8 == 0) // After every 8 elements creates newline
    {
      cout << '\n';
    }

    printedIndex++;
    count++; // counts how many elements there are so newline can be created
  }

  cout << endl;

  return 0;
}
