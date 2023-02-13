//Program designed to take a certain amount of user entered disks
//that all start on peg 1, and get all the disks arranged on peg 2
//from smallest on top to largest on bottom without having a larger
//ever being placed atop a smaller disk.
#include <iostream>
using namespace std;

void move(int, int, int, int);

int main(int argc, char *argv[])
{
        int disk;
        disk = atoi(argv[1]);

        //The 3 pegs
        int starterPeg = 1;//initial peg to hold the disks
        int destPeg = 2;//final peg once all disks moved
        int tempPeg = 3;//temporary holding peg

        move(disk, starterPeg, tempPeg, destPeg);

        return 0;
}

//Function to get disks in assorted order
void move(int disk, int starterPeg, int tempPeg, int destPeg)
{
        //Once function has gone through enough recursions and gets to disk 1
        //if statement will execute to sort the first disk
        if(disk == 1)
        {
          cout << disk << " " << starterPeg << "->" << destPeg << endl;
          return;
        }

        //Two recursions to pass around disks in order to get all disks to peg 2

        move(disk - 1, starterPeg, destPeg, tempPeg);//destPeg & tempPeg trade values

        cout << disk << " " <<starterPeg << "->" << destPeg << endl;

        move(disk - 1, tempPeg, starterPeg, destPeg);//tempPeg & starterPeg trade values
}
