#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void initialVectors(vector<int> & , vector<string> &, int);
void printVectors(vector<int> , vector<string> , int);
void sortVectors(vector<int> &, vector<string> &, int);

int main()
{
  const int N=10;
  vector<int> IDs(N);
  vector<string> names(N);
  initialVectors(IDs, names, N);
  printVectors(IDs, names, N);
  cout << endl;
  sortVectors(IDs, names, N);
  printVectors(IDs, names, N);
}

void initialVectors(vector<int> &IDs, vector<string> &names, int N)
{
    
  ifstream ifs;
  
  ifs.open("StudentVector.txt");

  if ( ifs.fail())
  {
    cout << "File Open Error\n";
    exit(0);
  }

  for(int i=0;i<N;i++)
  {
    ifs >> IDs[i] >> names[i] ;
    if ( ifs.fail())
    {
      cout << "File Read Error\n";
      exit(0);
    }
  }   
}

void sortVectors(vector<int> &IDs, vector<string> &names, int N)
{
    
  int A, B;
  string temp;
  for(int i=0; i<N; i++)
  {
    A = IDs[i];
    B = i;
    for(int j=i+1; j<N; j++)
    {
      if ( A > IDs[j] )
      {
        A = IDs[j];
        B = j;
      }
    }
    IDs[B] = IDs[i];
    IDs[i] = A;

    temp = names[B];
    names[B] = names[i];
    names[i] = temp;
  }
}

void printVectors(vector<int> IDs, vector<string> names, int N)
{
  for(int i=0; i<N; i++)
  {
    cout << IDs[i] << "\t" << names[i] << "\n";
  }
  cout << endl;
}