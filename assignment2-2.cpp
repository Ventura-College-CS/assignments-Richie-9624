#include <iostream>

using namespace std;

void printArray(double * const n, int N);

int main()
{
  double array[3] = {1, 2, 3};
  double *p;
  p = array;

  printArray(p, 3);
}

void printArray(double * const n, int N)
{
  for(int i = 0; i < N; i++)
  {
    cout << n[i] << endl;
  }
}
