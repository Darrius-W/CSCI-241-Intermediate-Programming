#include "sml.h"
#include "simplesim.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor initializing and declaring all the needed variables.
//Then assigns all 100 memory locations to "7777"
simplesim::simplesim()
{
        accumulator = 0;
        instruction_counter = 0;
        instruction_register = 0;
        operation_code = 0;
        operand = 0;

        int num = 0;

        while (num < 100)//loop sets all elements to 7777
        {
           memory[num] = 7777;
           num++;
        }
}

//checks instructions for validity
bool simplesim::load_program()
{
        int instruction;
        int totalInstructions = 0;

        while (cin >> instruction && instruction != -99999)
        {
           if (instruction > -9999 && instruction < 9999)//accept instruction within range
           {
                if (totalInstructions >= 100)//decision statement for too many instructions
                {
                    cout << "*** ABEND: pgm load: pgm too large ***\n\n";
                    return false;
                }
                else
                {
                    memory[totalInstructions] = instruction;//assigning valid instructions to memory location
                    instruction++;
                    totalInstructions++;
                }
           }
           else//decision statement for when a valid input wasn't entered
           {
                cout <<  "*** ABEND: pgm load: invalid word ***\n\n";
                return false;
           }
        }

        return true;
}

void simplesim::execute_program()
{
   int data, result;
   bool done = false;
   while (!done)
   {
    // instruction fetch
    if (instruction_counter >= 0 && instruction_counter < 100)//valid range
    {
        instruction_register = memory[instruction_counter];//if within range, instruction register is assigned to current memory location

        operation_code = instruction_register / 100;//operation set to rounded digit
        operand = instruction_register % 100;//operand set to remainder
    }
    else//if instruction counter out of range
    {
        cout << "*** ABEND: addressability error***\n\n";
        return;
    }

    if (operation_code == HALT)//the final operation that is read to signify the end of the loop
    {
       cout << "*** Simplesim execution terminated ***\n\n";
       return;
    }


    switch (operation_code)
    {
        case READ:

            cin >> data;//reads in one number each time looped through

            if (data >= -9999 && data <= 9999)//range set for data
            {
                memory[operand] = data;//value in data gets assigned a memory location

                cout << left << "READ: " << showpos << setfill('0') << internal << setw(5) << data
                     << noshowpos << setfill(' ') << "\n";
                break;
            }
            else//decision statement for invalide input
            {
                cout << "*** ABEND: illegal input ***\n\n";
                return;
            }


        case WRITE://displays data value set in memory
            cout << left << showpos << setfill('0') << internal << setw(5)
                 << memory[operand] << noshowpos << setfill(' ') << "\n";
           break;

        case LOAD:
            accumulator = memory[operand];
            break;

        case STORE:
            memory[operand] = accumulator;
            break;

        case ADD:
            result = accumulator + memory[operand];


            if (result < -9999)//if below range
            {
                cout << "*** ABEND: underflow ***\n\n";
                return;
            }
            else if (result > 9999)//if above range
            {
                cout << "*** ABEND: overflow ***\n\n";
                return;
            }
            else//if value is within range, accumulator is assigned to result
                accumulator = result;

            break;

        case SUBTRACT:
            result = accumulator - memory[operand];

            if (result < -9999)
            {
                cout << "*** ABEND: underflow ***\n\n";
                return;
            }
            else if (result > 9999)
            {
                cout << "*** ABEND: overflow ***\n\n";
                return;
            }
            else
                accumulator = result;

            break;

        case MULTIPLY:
            result = accumulator * memory[operand];

            if (result < -9999)
            {
                cout << "*** ABEND: underflow ***\n\n";
                return;
            }
            else if (result > 9999)
            {
                cout << "*** ABEND: overflow ***\n\n";
                return;
            }
            else
                accumulator = result;

            break;

        case DIVIDE:
           if (memory[operand] == 0)//touching base because can't divide by 0
           {
                cout << "*** ABEND: attempted division by 0 ***\n\n";
                return;
           }

           result = accumulator * memory[operand];

           if (result < -9999)
            {
                cout << "*** ABEND: underflow ***\n\n";
                return;
            }
            else if (result > 9999)
            {
                cout << "*** ABEND: overflow ***\n\n";
                return;
            }
            else
                accumulator = result;

            break;

        case BRANCH:
            instruction_counter = operand;

            break;

        case BRANCHNEG:
            if (accumulator < 0)
                instruction_counter = operand;
            else
                instruction_counter++;

            break;

        case BRANCHZERO:
            if (accumulator == 0)
                instruction_counter = operand;
            else
                instruction_counter++;

            break;


        default:
            cout << "*** ABEND: invalid opcode ***\n\n";
            return;
    }

   //instruction counter will increment without special circumstances if operation code doesn't equal any of the following operation
   if (operation_code != BRANCH && operation_code != BRANCHZERO && operation_code != BRANCHNEG && !done)
        instruction_counter++;
   }
}

void simplesim::dump() const
{
        cout << left << setw(24) << "REGISTERS:" << "\n";

        cout << left << setw(24) << "accumulator:" << showpos << setfill('0') << internal
             << setw(5) << accumulator << noshowpos << setfill(' ') << "\n";

        cout << left << setw(24) <<  "instruction_counter:" << setfill('0') << right << setw(2)
             << instruction_counter << setfill(' ') << "\n";

        cout << left << setw(24) << "instruction_register:" << showpos << setfill('0') << internal
             << setw(5) << instruction_register << noshowpos << setfill(' ') << "\n";

        cout << left << setw(24) << "operation_code:" << setfill('0') << right << setw(2)
             << operation_code << setfill(' ') << "\n";

        cout << left << setw(24) << "operand:" << setfill('0') << right << setw(2) << operand
             << setfill(' ') << "\n" << "\n";

        cout << "MEMORY:\n" << "  ";


        int num = 0;

        while (num < 10)//prints all x-coordinates
        {
           cout << setw(6) << num;
           num++;
        }

        num = 0;
        int y_coor = 0;

        while (num < 100)//prints all y-coordinates
        {
           if (num % 10 == 0)
           {
                cout << endl;

                cout << setw(2) << y_coor << " " << internal << showpos << setfill('0') << setw(5)
                << memory[num] << " " << noshowpos << setfill(' ');

                y_coor += 10;
           }
           else
                cout << internal << showpos << setfill('0') << setw(5)
                << memory[num] << " " << noshowpos << setfill(' ');


          num++;
        }
        cout << endl;
}

