#include <iostream>
#include <stdlib.h>

using namespace std;

void fullupArray(int *arr) //function to fill the values
{
  for(int i = 0; i < 10; i++)
  {
    arr[i] = rand() % 100; //rand() function generates numbers from 0-99
  }
}

void printArray(int *arr) //function to print array
{
  for(int i = 0; i < 10; i ++)
  {
    cout << arr[i] << " ";
  }
  return;
}

int main()
{
  int *arr = new int[10];  //creates space for 10 integers

  fullupArray(arr); //fill up the array from 0-99 randomly

  printArray(arr);  //prints the array

  return 0;
}