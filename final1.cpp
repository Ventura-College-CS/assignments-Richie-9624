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

string BinarySearch(Course arr[10], int id, int start, int end)
{
  int mid = (int)(start+end)/2;
  if(end>start)
  {
    if(arr[mid].id == id)
    {
      return "found";
    }
    else if(arr[mid].id>id)
    {
      return BinarySearch(arr, id, start, mid);
    }
    else if(arr[mid].id<id)
    {
      return BinarySearch(arr, id, mid+1, end);
    }
  }
  return "not found";
}

int main()
{
  Course c[10] = {Course(10001, "Calculus", 3), Course(10002, "History", 4), Course(10003, "Algebra", 5), Course(10004, "Geometry", 1), Course(10005, "Woodshop", 2), Course(10006, "Metalshop", 1), Course(10007, "Chemistry", 5), Course(10008, "Music", 5), Course(10009, "Theatre", 3), Course(10010, "Communication", 1)};

  int id;
  cout << "enter course id: ";
  cin >> id;
  sort(c);
  cout << BinarySearch(c, id, 0, 10);
  return 0;
}
