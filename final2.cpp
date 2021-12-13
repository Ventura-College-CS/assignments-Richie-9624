#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Course  //student class from 1st question then edited more
{
  private:   //instance members
    int id;
    string name;
    int credit;

  public:  //defualt constructor
    Course()
    {
      id = 0;
      name = " ";
      credit = 0;
    }
        //parameterized constructor
    Course(int ID, string sname, int coursecredit)  
    {
      id = ID;
      name = sname;
      credit = coursecredit;
    }

    int getID(){return id;}  //getters
    string getName(){return name;}
    int getCredit(){return credit;}
};

void Array(Course arr[10])
{
  int ID;
  int coursecredit;
  string sname;

  ifstream ifs("final.txt");

  for(int i = 0; i<10; i++)
  {
    ifs >> ID >> sname >> coursecredit;
    arr[i] = Course(ID, sname, coursecredit);
  }
  ifs.close();
}

void Print(Course arr[10])
{
  cout << "array: " << endl;
  for(int i = 0; i < 10; i++)//print all 10 objects
  {
    cout << arr[i].getID() << " " << arr[i].getName() << " " << arr[i].getCredit() << endl;
  }
}

int Partition(Course arr[10], int start, int end)
{
  int pivot = arr[end].getID();
  int a = -1;
  for (int i = 0; i < end; i++)
  {
    if(arr[i].getID() < pivot)
    {
      swap(arr[++a], arr[i]);
    }
  }
  swap(arr[a+1], arr[end]);
  return a+1;
}

void Quicksort(Course arr[10], int start, int end)
{

}
