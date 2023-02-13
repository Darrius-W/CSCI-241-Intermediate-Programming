#include <cstring>
#include <cctype>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "mystack.h"
#include "inpost.h"
#include "sml.h"
#include <iostream>
using namespace std;

struct table_entry
{
    int symbol;
    char type;        // 'C' constant, 'L' Simple line number, 'V' variable
    int location;     // Simplesim address (00 to MEMSIZE-1)
};

class scc
{
  private:
        static const int MEMSIZE = 100;
        static const int SYMBOL_TABLE_SIZE = 1000;
        int memory[MEMSIZE];
        int data[MEMSIZE];
        int ndata;
        table_entry symbol_table[SYMBOL_TABLE_SIZE];
        int flags[MEMSIZE];
        int next_instruction_addr;
        int next_const_or_var_addr;
        int next_symbol_table_idx;

  public:
        scc();
        void checkRoomInArr()const;
        void firstPass();
        void displayArr()const;
        int symbolSearch(int, char);
        int locationOfSym(string);
        void dataArrDisplay()const;
        void memoryArrDisplay()const;
        void enoughRoomPostfix(int);
        void secondPass();
        void formattedDisplay();
};

//main function
int main(){
  scc obj;

  obj.firstPass();
  obj.secondPass();
  obj.formattedDisplay();
  //obj.memoryArrDisplay();
  return 0;
}

//initializing all data members
scc::scc(){
          int index = 0;
          next_instruction_addr = 0;
          next_const_or_var_addr = MEMSIZE-1;
          next_symbol_table_idx = 0;
          ndata = 0;

          while(index < MEMSIZE){  //loop to initialize every element
            memory[index] = 7777;
            flags[index] = -1;

            index++;
          }
}

//method to make sure there is room in the array
void scc::checkRoomInArr()const{
  if (next_instruction_addr >= MEMSIZE || next_instruction_addr > next_const_or$
    cout << "*** ERROR: ran out Simplesim memory ***\n";
    exit(1);
  }
}

//First Pass
void scc::firstPass(){
  string buffer1, buffer2, line_number, command;

  while (getline(cin, buffer1))
  {
    buffer2 = buffer1;         // buffer2 used for 'let'
    istringstream ss(buffer1);

    ss >> line_number;

    // ... code to add line_number to symbol table, type 'L' ...
    symbol_table[next_symbol_table_idx].symbol = atoi(line_number.c_str());
    symbol_table[next_symbol_table_idx].type = 'L';

    symbol_table[next_symbol_table_idx].location = next_instruction_addr;
    next_symbol_table_idx++;

    ss >> command;

    //the conditional statements for the first pass
    if (command == "input")
    {
      // ... code to process 'input' command ...
      string name;
      ss >> name;
      locationOfSym(name);
      checkRoomInArr();

      memory[next_instruction_addr] = READ*100 + locationOfSym(name);
      next_instruction_addr++;
    }

    else if (command == "data")
    {
      // ... code to process 'data' command ...
      int value;
      ss >> value;

      if (ndata == MEMSIZE - 1){
        cout << "***ERROR: too many data lines***" << endl;
        exit(1);
      }
      /*else{
        data[ndata] = value;
        ndata++;
      }*/
      data[ndata] = value;
      ndata++;

    }

    else if (command == "let")
    {
      // ... code to process 'let' command ...
      string leftVar;
      ss >> leftVar;
      locationOfSym(leftVar);

      size_t sub = buffer2.find_first_of("=");
      string infix = buffer2.substr(sub + 2, string::npos);
      string postfix = convert( infix );


      stringstream ss2(postfix);
      int subscript = 0;
      string eval;

      while (ss2 >> eval){
        if (isdigit(eval[0]) || islower(eval[0])){//condition statment for if o$

          checkRoomInArr();
          memory[next_instruction_addr] = LOAD*100 + locationOfSym(eval);
          next_instruction_addr++;
          checkRoomInArr();
          memory[next_instruction_addr] = STORE*100;
          flags[next_instruction_addr] = -3-subscript;

          next_instruction_addr++;
          subscript++;
        }


        else if ((eval[0] == '+') || (eval[0] == '*')){//condition statement to$

          checkRoomInArr();
          memory[next_instruction_addr] = LOAD*100;
          subscript--;

          flags[next_instruction_addr] = -3-subscript;
          next_instruction_addr++;

          checkRoomInArr();
          if (eval[0] == '+'){
            memory[next_instruction_addr] = ADD*100;
          }

          else{
            memory[next_instruction_addr] = MULTIPLY*100;
          }
          subscript--;
          flags[next_instruction_addr] = -3-subscript;
          next_instruction_addr++;

          checkRoomInArr();
          memory[next_instruction_addr] = STORE*100;
          flags[next_instruction_addr] = -3-subscript;

          next_instruction_addr++;
          subscript++;
        }


        else if (eval[0] == '-' || eval[0] == '/'){//condition statement to che$

          checkRoomInArr();
          memory[next_instruction_addr] = LOAD*100;
          subscript--;
          flags[next_instruction_addr] = -3-subscript;
          next_instruction_addr++;

          checkRoomInArr();
          memory[next_instruction_addr] = STORE*100;
          flags[next_instruction_addr] = -2;
          next_instruction_addr++;

          checkRoomInArr();
          memory[next_instruction_addr] = LOAD*100;
          subscript--;
          flags[next_instruction_addr] = -3-subscript;
          next_instruction_addr++;

          checkRoomInArr();

          if (eval[0] == '-')
            memory[next_instruction_addr] = SUBTRACT*100;
          else
            memory[next_instruction_addr] = DIVIDE*100;

          flags[next_instruction_addr] = -2;
          next_instruction_addr++;

          checkRoomInArr();
          memory[next_instruction_addr] = STORE*100;
          flags[next_instruction_addr] = -3-subscript;

          next_instruction_addr++;
          subscript++;
        }
      }

      checkRoomInArr();
      memory[next_instruction_addr] = LOAD*100;
      flags[next_instruction_addr] = -3;
      next_instruction_addr++;

      checkRoomInArr();
      memory[next_instruction_addr] = STORE*100 + locationOfSym(leftVar);
      next_instruction_addr++;
    }


    else if (command == "rem")
    {
      // ... code to process 'rem' command ...
    }


    else if (command == "end")
    {
      // ... code to process 'end' command ...
      checkRoomInArr();
      memory[next_instruction_addr] = HALT*100;
      next_instruction_addr++;
    }


    else if (command == "print")
    {
      // ... code to process 'print' command ...
      string name;
      ss >> name;
      locationOfSym(name);
      checkRoomInArr();

      memory[next_instruction_addr] = WRITE*100 + locationOfSym(name);
      next_instruction_addr++;
    }


    else if (command == "goto")
    {
      // ... code to process 'goto' command ...
      checkRoomInArr();
      int value;
      ss >> value;

      if (symbolSearch(value, 'L') == -1){
        memory[next_instruction_addr] = BRANCH*100;
        flags[next_instruction_addr] = value;
        next_instruction_addr++;
      }

      else{
        memory[next_instruction_addr] = BRANCH*100 + symbol_table[symbolSearch($
        next_instruction_addr++;
      }
    }


    else if (command == "if")
    {
      // ... code to process 'if' command ...
      string left_operand, relational_operator, right_operand, thegoto;
      int lineNum;
      ss >> left_operand;

      locationOfSym(left_operand);



      ss >> relational_operator;
      ss >> right_operand;
      locationOfSym(right_operand);

      ss >> thegoto;
      ss >> lineNum;
      int loc = symbolSearch(lineNum, 'L');
      checkRoomInArr();

      memory[next_instruction_addr] = LOAD*100;
      next_instruction_addr++;

      checkRoomInArr();
      memory[next_instruction_addr] = SUBTRACT*100;
      next_instruction_addr++;

      checkRoomInArr();


      //relational operator !=
      if (relational_operator == "!="){
        memory[next_instruction_addr] = BRANCHZERO*100 + (next_instruction_addr$
        next_instruction_addr++;
      }
      else{

        if(loc == -1){
          memory[next_instruction_addr] = 0;
          flags[next_instruction_addr] = lineNum;
          next_instruction_addr++;
        }

        else{
          memory[next_instruction_addr] = symbol_table[loc].location;
          next_instruction_addr++;
        }
      }
      //relational operator <
      if (relational_operator == "<"){
        memory[next_instruction_addr-3] += locationOfSym(left_operand);
        memory[next_instruction_addr-2] += locationOfSym(right_operand);
        memory[next_instruction_addr-1] += BRANCHNEG*100;
      }


      //relational operator <=
      if (relational_operator == "<="){
        memory[next_instruction_addr-3] += locationOfSym(left_operand);
        memory[next_instruction_addr-2] += locationOfSym(right_operand);
        memory[next_instruction_addr-1] += BRANCHNEG*100;
        checkRoomInArr();

        if (loc == -1){
          memory[next_instruction_addr] = BRANCHZERO*100;
          flags[next_instruction_addr] = lineNum;
          next_instruction_addr++;
        }

        else{
          memory[next_instruction_addr] = BRANCHZERO*100 + symbol_table[loc].lo$
          next_instruction_addr++;
        }
      }


      //relational operator >
      if (relational_operator == ">"){
        memory[next_instruction_addr-3] += locationOfSym(right_operand);
        memory[next_instruction_addr-2] += locationOfSym(left_operand);
        memory[next_instruction_addr-1] += BRANCHNEG*100;
      }


      //relational operator >=
      if (relational_operator == ">="){
        memory[next_instruction_addr-3] += locationOfSym(right_operand);
        memory[next_instruction_addr-2] += locationOfSym(left_operand);
        memory[next_instruction_addr-1] += BRANCHNEG*100;

        checkRoomInArr();

        if (loc == -1){
          memory[next_instruction_addr] = BRANCHZERO*100;
          flags[next_instruction_addr] = lineNum;
          next_instruction_addr++;
        }

        else{
          memory[next_instruction_addr] = BRANCHZERO*100 + symbol_table[loc].lo$
          next_instruction_addr++;
        }
      }


      //relational operator ==
      if (relational_operator == "=="){
        memory[next_instruction_addr-3] += locationOfSym(left_operand);
        memory[next_instruction_addr-2] += locationOfSym(right_operand);
        memory[next_instruction_addr-1] += BRANCHZERO*100;
      }


      //relational operator !=
      if (relational_operator == "!="){
        memory[next_instruction_addr-3] += locationOfSym(left_operand);
        memory[next_instruction_addr-2] += locationOfSym(right_operand);
        checkRoomInArr();

        if (loc == -1){
          memory[next_instruction_addr] = BRANCH*100;
          flags[next_instruction_addr] = lineNum;
          next_instruction_addr++;
        }

        else{
          memory[next_instruction_addr] = BRANCH*100 + symbol_table[loc].locati$
          next_instruction_addr++;
        }
      }
    }
  }
}

//displays contents of the symbol table array
void scc::displayArr()const{
  for (int inc = 0; inc < next_symbol_table_idx; inc++){

    if (symbol_table[inc].type == 'V'){
      cout << (char)symbol_table[inc].symbol << " " << symbol_table[inc].type
           << " " << symbol_table[inc].location << endl;
    }

    else{
      cout << symbol_table[inc].symbol << " " << symbol_table[inc].type
           << " " << symbol_table[inc].location << endl;
    }
  }
}

//method to searche symbol table for specific symbol
int scc::symbolSearch(int sym, char symType){
  for (int i = 0; i < next_symbol_table_idx; i++){
    if (sym == symbol_table[i].symbol && symType == symbol_table[i].type)
      return i;//returns subcript of symbol instance
  }
  return -1;
}

//method to find location of symbol in symbol table
int scc::locationOfSym(string sym){
  char typeOfSym;
  int symVal, symLocation;
  int i = 0;

  //check if a variable name
  if (isalpha(sym[i])){
    typeOfSym = 'V';
    symVal = sym[i];
  }

  else{
    string temp;
    typeOfSym = 'C';
    temp += sym[i];
    i++;

    while (isdigit(sym[i])){//check for digits in string
      temp += sym[i];
      i++;
    }
    symVal = stoi(temp);//stores all string digits in symVal
  }

  if(symbolSearch(symVal, typeOfSym) == -1){//if the symbol wasn't located
    symLocation = next_const_or_var_addr;
    symbol_table[next_symbol_table_idx].symbol = symVal;
    symbol_table[next_symbol_table_idx].type = typeOfSym;
    symbol_table[next_symbol_table_idx].location = symLocation;

    next_symbol_table_idx++;
    checkRoomInArr();

    if (isalpha(sym[i])){
      memory[next_const_or_var_addr] = 0;
      next_const_or_var_addr--;
    }

    else{
      memory[next_const_or_var_addr] = atoi(sym.c_str());
      next_const_or_var_addr--;
    }
  }

  else//if the symbol was located
    symLocation = symbol_table[symbolSearch(symVal, typeOfSym)].location;

  return symLocation;
}

//displays data array contents
void scc::dataArrDisplay()const{
  for (int i = 0; i < ndata; i++)
   cout << data[i] << endl;
}

//displays memory array contents
void scc::memoryArrDisplay() const{
  for (int i = 0; i < MEMSIZE; i++)
    cout << memory[i] << endl;
}

//method to check room for postfix
void scc::enoughRoomPostfix(int theSub){
  if (theSub < next_instruction_addr){
    cout << "*** ERROR: insufficient stack space ***\n" << endl;
    exit(1);
  }
}

//Second Pass
void scc::secondPass(){
  int sub = next_const_or_var_addr-1;
  int calc;

  for (int i = 0; i < next_instruction_addr; i++){
    if (flags[i] != -1){
      if (flags[i] > 0){
        memory[i] += symbol_table[symbolSearch(flags[i], 'L')].location;
      }

      if (flags[i] == -2){

        memory[i] += next_const_or_var_addr;
      }

      if (flags[i] < -2){
        calc = -3 - flags[i];
        enoughRoomPostfix(sub - calc);
        memory[i] += (sub - calc);
      }
    }
  }
}

//displays formatted versions of the memory array & data array
void scc::formattedDisplay(){
  for (int i = 0; i < MEMSIZE; i++){
    cout << left << showpos << setfill('0') << internal << setw(5) << memory[i]
         << noshowpos << setfill(' ') << endl;
  }

    cout << "-99999\n";

  for (int j = 0; j < MEMSIZE; j++){
    if (data[j] != 0){
      cout << left << internal << data[j] << endl;
    }
  }
}
