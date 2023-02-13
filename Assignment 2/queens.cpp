//Program places 8 queens in a 8x8 board in a way that no
//queen is attacking another
#include <iostream>
using namespace std;

const int SQUARE = 8;//constant max value for the two dimensional array

//Function that goes through all checks to see if a queen
// can safely be placed in a certain row/column.
//If not the function returns false showing that it cannot be placed in
//desired position
bool isSafe(int board[][SQUARE], int desiredRow, int desiredCol)
{
        //checks rows above current desired row for queen, returns false if there is
        for (int i = 0; i <= desiredRow; i++)
        {
           if (board[i][desiredCol] == 1)
                return false;
        }

        //checks diagonal left space for queen, and returns false if there is one
        for (int i = desiredRow, ii = desiredCol; i >= 0 && ii >= 0; i--, ii--)
        {
           if (board [i][ii] == 1)
                return false;
        }

        //checks diagonal right space for queen, and returns false if there is one
        for (int i = desiredRow, ii = desiredCol; i >= 0 && ii <= 7 && ii >= 0; i--, ii++)
        {
           if (board[i][ii] == 1)
                return false;
        }

        return true;//After all checks successfully run through then a queen can be placed in postion, so returns true
}

//Function that iterates through each column for isSafe function to test if its safe
bool placeQueen(int board[][SQUARE], int desiredRow)
{
        if (7 < desiredRow)//if function reaches end of board it stops
             return true;

        for (int column = 0; column < SQUARE; column++)//loops through each column
        {
           if (isSafe(board, desiredRow, column))//executes if isSafe is true
           {
                 board[desiredRow][column] = 1;

                 //Recursive backtrack statement to check if next row can have a queen placed in said column
                 if (placeQueen(board, desiredRow + 1))
                 {
                        return true;
                 }
                 board[desiredRow][column] = 0;
           }
        }
        return false;
}

int main()
{
        int board[SQUARE][SQUARE] = { 0 };//inital board setup
        int row = 0;

        //loop to pass through each row through placeQueen function
        while (row < SQUARE)
        {
           placeQueen(board, row);
           row++;
        }

        //loop to print the board after all queens are placed
        for (int i = 0; i < 8; i++)
        {
           for (int ii = 0; ii < 8; ii++)
           {
                cout << board[i][ii] << " ";
           }
           cout << "\n";
        }

        return 0;
}
