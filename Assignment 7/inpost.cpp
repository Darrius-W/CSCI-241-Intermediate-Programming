#include <iostream>
#include <cctype>
#include <cstdlib>
#include "mystack.h"
#include "inpost.h"
using namespace std;

//checks if the arguement passed is an operator
bool testForOp(char op)
{
  if (op == '+' || op == '-' || op == '*' ||
      op == '/' || op == '~' || op == '^')
  {
        return true;
  }
  return false;
}

//tests the arguement for precedence and returns integer value based on importance
int pemdas(char op)
{
  if (op == '~' || op == '^')
    return 4;

  else if (op == '*' || op == '/')
    return 3;

  else if (op == '+' || op == '-')
    return 2;

  else
    return 1;
}

//converts infix to postfix
string convert(const string& infix)
{
  string postfix;
  char topValue;
  mystack stackObj;
  int thePemdas;

  for (size_t i = 0; i < infix.length(); ++i)//loop to go through all infix characters
  {
    if (isalpha(infix[i])){//checks if character is alphabetic

      if (postfix.length() != 0)//checks if the end of the postfix has been reached
        postfix += ' ';

      postfix += infix[i];//if character is alphabetic it is added to the postfix
    }

    else if (isdigit(infix[i])){//checks if characters are numeric

       if (postfix.length() != 0)
          postfix += ' ';

       for (size_t q = i; q <= infix.length(); ++q){//loop for if numbers have more than a ones place

          if (isdigit(infix[q])){
             postfix += infix[q];
          }
          else{
             i = q - 1;
             break;
          }
       }
    }

    else if (infix[i] == '('){//checks for left parenthesis

       stackObj.push(infix[i]);//pushes character ontop of the stack
    }

    else if (infix[i] == ')'){//checks for right parenthesis

       topValue = stackObj.top();//assigns character atop stack to a variable

       stackObj.pop();//pops the top character off the stack

       while (!stackObj.empty() && topValue != '('){

          if (postfix.length() != 0)
             postfix += ' ';

          postfix += topValue;
          topValue = stackObj.top();
          stackObj.pop();
       }
    }

    else if (testForOp(infix[i])){//checks for operator
       thePemdas = pemdas(infix[i]);//assigns precedence of infix[i] to an integer value returned based on importance

       while (!stackObj.empty() && pemdas(stackObj.top()) >= thePemdas){
         if (postfix.length() != 0)
           postfix += ' ';

         topValue = stackObj.top();
         postfix += topValue;
         stackObj.pop();
       }
       stackObj.push(infix[i]);
    }
  }

 while (!stackObj.empty()){
  if (postfix.length() != 0)
    postfix += ' ';

  topValue = stackObj.top();

  postfix += topValue;

  stackObj.pop();
 }
  return postfix;
}
