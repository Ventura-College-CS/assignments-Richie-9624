#include <iostream>
#include<fstream>
#define MAX_LEN 20
#define NUM_SCORES 3

using namespace std;

struct Students
{
  int sid;
  char sname[MAX_LEN];
  int scores[NUM_SCORES];
};

void makeStudents(Students* ptr, int size)
{
  //read from file
  ifstream in;
  //open file called students.txt
  in.open("students.txt");
  //check if file can be opened
  if (!in)
  {
    cout << "students.txt cannot be opened\n";
    return;
  }
  //read from file

  for (int i = 0; i < size; i++)
  {
    if (!in.eof())
    in >> ptr[i].sid >> ptr[i].sname >> ptr[i].scores[0] >> ptr[i].scores[1] >> ptr[i].scores[2];
  }
}

void printStudents(Students* ptr, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "sid: " << ptr[i].sid << " " << "sname: " << ptr[i].sname << " " << "marks: " << ptr[i].scores[0] << " " << ptr[i].scores[1] << " " << ptr[i].scores[2] << endl;
  }
}

void sortStudents(Students* ptr, int size)
{
  int sum1 = 0, sum2 = 0;
  Students tmp;
  //sort students by scores sum
  //bubble sort
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10-i-1; j++)
    {
      sum1 = ptr[j].scores[0] + ptr[j].scores[1] + ptr[j].scores[2];
      sum2 = ptr[j + 1].scores[0] + ptr[j + 1].scores[1] + ptr[j + 1].scores[2];
      if (sum1 > sum2)
      {
        //swap two info
        tmp = ptr[j];
        ptr[j] = ptr[j + 1];
        ptr[j + 1] = tmp;
      }
    }
  }
}

int main() 
{
  Students* ptr = NULL;
  ptr = new Students[10];
  //first read from file using function makeStudents
  makeStudents(ptr, 10);
  //print before sorting
  cout << "Student info before sorting...." << endl;
  printStudents(ptr, 10);
  //print student info after sorting
  sortStudents(ptr, 10);
  //print students info after sorting
  cout << "Student info after sorting...." << endl;
  printStudents(ptr, 10);
}
