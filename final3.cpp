#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float input(char ch) //uses to return float from user input
{
  int value;
  value = ch;
  return float(value -'0');
}

int Operand(char ch)
{
  if(ch >= '0' && ch <= '9') //single digit number
  {
    return 1;  //if character is an operand
  }
  return -1; //if character isn't an operand
}

int Operator(char ch)    //if any other symbol then gives an error
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '^' || ch == '/')
  {
    return 1; //if character is an operator
  }
  return -1;  //if character isn't an operator
}

float Operations(int a, int b, char op) 
//actual operations for each symbol
{
  if(op == '+')
  {
    return b+a; 
  }
  else if(op == '-')
  {
    return b-a;
  }
  else if(op == '*')
  {
   return b*a;
  }
  else if(op == '/')
  {
    return b/a;
  }
  else if(op == '^')
  {
    return pow(b,a); //finds b^a
  }
  else 
  return INT_MIN;  //will return negative infinity
}

float Pfix(string postfix)
{
  int a;
  int b;

  stack<float>stac;  //creates the stack
  string::iterator it;

  for( it = postfix.begin(); it != postfix.end(); it++ )
  {
    if (Operator(*it) != -1)
    {
      a = stac.top();  //reads elements and does postfix on them
      stac.pop();
      b = stac.top();
      stac.pop();
      stac.push(Operations(a, b, *it));
    }

    else if(Operand(*it) > 0)
    {
      stac.push(input(*it));
    }
  }
  return stac.top();
}

int main()
{
  string post;  //creates string to take user input
  cout<< "enter in your postfix expression then press enter" << endl;
  cin >> post;
  cout << post << " " << "=" << " " << Pfix(post) << endl;
  cout << endl;
}

