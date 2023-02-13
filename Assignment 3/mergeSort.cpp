//Program is designed to use the merge sort algorithm to split the array
//until it can't anymore and then sort it by putting it back together.
#include <iostream>
#include <iomanip>
using namespace std;

//Function to rearrange values in original array by assigning the smaller
//values compared by each half of the array to the temp array
void merge(int mergeArr[], int start_indx, int mid_indx, int end_indx)
{
        int temp[1000];
        int i = start_indx;
        int j = mid_indx + 1;
        int k = start_indx;
        int increment = start_indx;

        //loop comparing values of first and second halves of the array
        //one by one, whichever is smaller gets assigned to temp[k]
        while (i <= mid_indx && j <= end_indx)
        {
           if (mergeArr[i] < mergeArr[j])
           {
              temp[k] = mergeArr[i];
              i++;//if mergeArr[i] is smaller 'i' will increase index and 'j' will not
              k++;
           }
           else
           {
              temp[k] = mergeArr[j];
              j++;//if mergeArr[j] is smaller 'j' will increase index and 'i' will not
              k++;
           }
        }

        while (i <= mid_indx)//loop assigning all the rest of the 'i' values to temp array
        {
           temp[k] = mergeArr[i];
           i++;
           k++;
        }

        while (j <= end_indx)//loop assigning the rest of the 'j' values to temp array
        {
           temp[k] = mergeArr[j];
           j++;
           k++;
        }


        while (increment < k)//reassigning all the values in mergeArr to match that of temp array
        {
           mergeArr[increment] = temp[increment];
           increment++;
        }
}

//Function using recursion to continuously split the array until
//no longer able, then calls the merge function to sort the values
void merge_sort(int mergeArr[], int start_indx, int end_indx)
{
        int mid_indx;

        if (start_indx < end_indx)
        {
           mid_indx = (start_indx + end_indx) / 2;//to calculare middle index

           //the two recursions below continuously split the array
           merge_sort(mergeArr, start_indx, mid_indx);
           merge_sort(mergeArr, mid_indx + 1, end_indx);

           merge(mergeArr, start_indx, mid_indx, end_indx);//sorts the array
        }
}

int main()
{
        int element;
        int mergeArr[1000] = {};
        int start_indx = 0;
        int count = 1;
        int increment = 0;
        int increment2 = 0;

        while (cin >> element)//loop to get all the elements
        {
           mergeArr[increment] = element;
           increment++;
        }

        int end_indx = increment - 1;//subtract by one bc increment is 1 bigger than max because of loop

        merge_sort(mergeArr, start_indx, end_indx);

        while (increment2 < increment)//Loop to print all elements
         {
           if (count % 8 == 0 && increment2 + 1 < increment)//To create newline after 8 values
           {
              cout << setw(8) << mergeArr[increment2] << endl;//Printed to screen in right aligned manner
           }

           else if (increment2 + 1 >= increment)//If statement prevents extra newline at end of output
              cout << setw(8) << mergeArr[increment2];

           else
              cout << setw(8) << mergeArr[increment2] << " ";

           increment2++;
           count++;
        }

        cout << endl;

        return 0;
}
