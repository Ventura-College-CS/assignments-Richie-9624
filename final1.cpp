#include <iostream>

using namespace std;

class Course
{
  public:
    int id;
    string name;
    int credit;

    Course(int ID, string sname, int coursecredit)
    {
      id = ID;
      name = sname;
      credit = coursecredit;
    }
};

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(Course arr[10])
{
  for(int i = 0; i < 10; i++ )
  {
    for (int j = 0; j < 10-i-1; i++)
    {
      if(arr[j].id > arr[j+1].id)
      {
        swap(&arr[j].id, &arr[j+1].id);
        string temp = arr[j].name;
        arr[j].name = arr[j+1].name;
        arr[j+1].name = temp;
        swap(&arr[j].credit, &arr[j+1].credit);
      }
    }
  }
}



