#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LEN = 20;
const int NUM_SCORES = 3;

struct Students
{
  int sid;
  char sname[MAX_LEN];
  double scores[NUM_SCORES];
};

Students *makeStudents(int);
void printStudents(Students * const, int);
void sortStudents(Students * const, int);

Students *makeStudents(int N)
{
  ifstream ifs;
  Students *ptr = new Students[N];

  ifs.open("students.txt");
  if (ifs.fail())
  {
    cerr << "Error unable to open the file";
    exit(0);
  }

  for (int i = 0; i < N; i++)
  {
    ifs >> (ptr+i) ->sid >> (ptr+i)->sname;

    for (int j = 0; j < NUM_SCORES; j++)
    {
      ifs >> (ptr+i)->scores[j];
      if (ifs.fail())
      {
          cerr << "File Read Error";
          exit(0);
      }
    }
  }

  ifs.close();
  return ptr;
}

void printStudents(Students * const ptr, int N)
{
  for (int i = 0; i < N; i++)
  {
    cout << (ptr+i)->sid << " ";
    cout << (ptr+i)->sname << " ";
    for (int j = 0; j < NUM_SCORES; j++)
        cout << (ptr+i)-> scores[j] << " ";
    cout << endl;
  }
}

void sortStudents(Students * const ptr, int N)
{
  double *sumptr = new double[N]; 
  double sum;

  for (int i = 0; i < N; i++)
  {
    sum = 0;
    for (int j = 0; j < NUM_SCORES; j++)
        sum += (ptr+i)->scores[j];
    *(sumptr+i) = sum; 
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = i+1; j < N; j++)
    {
      if (*(sumptr+i) > *(sumptr+j)) 
      {
        Students temp = *(ptr+i);
        *(ptr+i) = *(ptr+j);
        *(ptr+j) = temp;  
        sum = *(sumptr+i); 
        *(sumptr+i) = *(sumptr+j);
        *(sumptr+j) = sum;
      }
    }
  }

  delete sumptr;

}

int main()
{
  const int N = 10;
  Students *ptr;
  ptr = makeStudents(N);
  cout << "Students sorted by score sum: " << endl;
  cout << endl;
  sortStudents(ptr, N);
  printStudents(ptr, N);
  delete ptr; 
}