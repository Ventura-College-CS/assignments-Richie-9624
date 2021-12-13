#include <iostream>
#include <fstream>

using namespace std;

class Course
{
  public:
    int id;
    string name;
    int credit;

    Course(){}

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

int BinarySearch(Course arr[10], int id, int start, int end)
{
  if(end > start)
  {
    int mid = (int)(start + end)/2;
    if(arr[mid].id == id)
    {
      return mid;
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
  return -1;
}
  

int main()
{
  Course c[10];
  int i = 0;
  int id;

  ifstream ifs ("final.txt");
  while (ifs >> c[i].id)
  {
    ifs >> c[i].name >> c[i].credit;
    i++;
  }
  ifs.close();

  sort(c);

  cout << "enter course ID: ";
  cin >> id;
  int pos = BinarySearch(c, id, 0, 10);
  if(pos == -1)
  {
    cout << "not found" << endl;
  }
  else
  {
    cout << "course id: " << c[pos].id << " name: " << c[pos].name << " Credits: " << c[pos].credit << endl;
  }
  return 0;
}
