//Program is designed to select a pivot in the array and place all the values
//larger then the pivot on one side and all the values smaller than
//the pivot on the other side. Then the program sorts the values on each side of
//the pivot one by one until they reach their respected bounds on each side.
#include <iostream>
#include <iomanip>
using namespace std;

//Function splits the array with larger values than the pivot on one
//side and smaller values on the left of the pivot
int partition(int quickArr[], int start_indx, int end_indx)
{
        int mid_indx = (start_indx + end_indx) / 2;//locates middle index of array

        swap(quickArr[start_indx], quickArr[mid_indx]);//mid value gets swapped to beginning of array

        int pivot_index = start_indx;//gets assign to new start value
        int pivot_value = quickArr[start_indx];
        int scannedIndex = start_indx + 1;

        //Loop checks from left to right looking for values greater than
        //pivot value if they are greater loop swaps them
        while (scannedIndex <= end_indx)
        {
           if (quickArr[scannedIndex] < pivot_value)
           {
                pivot_index = pivot_index + 1;//New pivot index value is now equal to the larger scan value
                swap(quickArr[pivot_index], quickArr[scannedIndex]);
           }
           scannedIndex = scannedIndex + 1;
        }

        swap(quickArr[start_indx], quickArr[pivot_index]);//swaps so all the smaller numbers are on the left
                                                    // of pivot index and larger on right
        return pivot_index;
}

//Function uses recursion to sort the elements on the left(smaller) of the pivot
//and to sort the elements on the right(larger) of the pivot
void quick_sort(int quickArr[], int start_indx, int end_indx)
{
        int pivotPoint;

        if (start_indx < end_indx)//Function ceases when when start index passes end index
        {
           pivotPoint = partition(quickArr, start_indx, end_indx);//Assigns the pivot found

           quick_sort(quickArr, start_indx, pivotPoint - 1);//Sorts all the elements to the left of pivot

           quick_sort(quickArr, pivotPoint + 1, end_indx);//Sorts all the elements to the right of pivot
        }
}

int main()
{
        int elements;
        int increment = 0;
        int quickArr[1000] = {};
        int start_indx = 0;
        int count = 1;
        int increment2 = 0;
        //Loop collects all the values in the array from file
        while (cin >> elements)
        {
           quickArr[increment] = elements;
           increment++;
        }

        int end_indx = increment - 1;//end is assigned to the final increment which is also the last index

        quick_sort(quickArr, start_indx, end_indx);


        //loop prints out all values in sorted order
        while (increment2 < increment)
        {
           if (count % 8 == 0 && increment2 + 1 < increment)//To create newline after 8 values
           {
              cout << setw(8) << quickArr[increment2] << endl;//Printed to screen in right aligned manner
           }

           else if (increment2 + 1 >= increment)//If statement prevent extra newline at end of output
              cout << setw(8) << quickArr[increment2];

           else
              cout << setw(8) << quickArr[increment2] << " ";

           increment2++;
           count++;
        }
        cout << endl;

        return 0;
}
