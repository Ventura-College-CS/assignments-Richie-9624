#include <iostream>
using namespace std;

int main()
{
  int num[5] = {5, 10, 15, 20, 25};  //unit space for a element : 4 bytes
  double d[5] = {1.0, 2.0, 3.0, 4.0, 5.0}; // * 8 bytes
  double *dptr;

  int *ptr;  

  ptr = num; //array is a constant pointer

  cout << *ptr << endl; //output: 
  cout << *(ptr+4) << endl; //output: // 4*(unit: 4) =16

  dptr = d;
  cout << *(dptr+4) << endl; //output : // 4*(unit: 8) =32
}