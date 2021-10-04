#include <iostream>
using namespace std;

int main()
{
  int num1 = 100;
  int num2 = 200;

  int *ptr1;

  cout << &num1 << endl; //memory address of num1
  cout << &num2 << endl; //memory address of num2

  ptr1 = &num1;  //the pointer varianle has the address of another variable

  cout << ptr1 << endl;  //same address as num1
  cout << *ptr1 << endl; //indirect (dereferenced) value 100

  ptr1 = &num2;
  cout << *ptr1 << endl; //indirect (dereferenced) value 200

  int *ptr2;

  ptr2 = ptr1;  //assigned the direct value(address) of ptr1

  
}