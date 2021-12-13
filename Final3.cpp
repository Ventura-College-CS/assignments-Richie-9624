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

int Operatrr(char ch)  
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '^' || ch == '/')
  {
    return 1;
  }
  return -1;
}
