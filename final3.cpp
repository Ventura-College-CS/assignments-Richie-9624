#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float input(char ch) //uses to return float from user input
{
  int value;
  value = ch;
  return 0;
}

int Operand(char ch)
{
  if(ch >= '0' && ch <= '9') //single digit number
  {
    return 1;  //if character is an operand
  }
  return -1; //if character isn't an operand
}

int Operator(char ch)  
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '^' || ch == '/')
  {
    return 1;
  }
  return -1;
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
      a = stac.top();
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
  string post;
  cout<< "enter in your expression" << endl;
  cin >> post;
  cout << "'" << post << "'" << "results: " << Pfix(post) << endl;
  cout << endl;
}

