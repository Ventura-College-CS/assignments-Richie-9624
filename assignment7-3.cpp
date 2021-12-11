#include <iostream>
using namespace std;

int binarySearch(int array[], int first, int last, int target)
{
  if (first > last)
    return -1;

  int mid = (first + last) / 2;

  if (array[mid] == target)
    return mid;

  if (array[mid] > target)
    return binarySearch(array, first, mid - 1, target);

  else
    return binarySearch(array, mid + 1, last, target);
  return -1;
}

int main()
{   
  int array[] = {1, 3, 6, 9, 12, 15, 18, 21, 24, 27};
  int target = 21;
  int x = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, 0, x-1, target);
  (result == -1)
    ? cout << "Element is not presented in array"
    : cout << "Element is presented at index " << result;
  return 0;  
}