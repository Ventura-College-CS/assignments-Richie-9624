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

// void swap(int *a, int *b)
// {
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }

