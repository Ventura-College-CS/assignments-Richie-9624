#include <iostream>
#include <fstream>

using namespace std;

class Course  //student class from 1st question/midterm then edited more
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


void Print(Course c[10])  //print out the array using the getters stated above
{
  cout << "array: " << endl;
  for(int i = 0; i < 10; i++)//print all 10 objects
  {
    cout << c[i].getID() << " " << c[i].getName() << " " << c[i].getCredit() << endl;
  }
}

int Partition(Course c[10], int start, int end)
{
  int pivot = c[end].getID();
  int a = -1;
  for (int b = 0; b < end; b++)
  {
    if(c[b].getID() < pivot)
    {
      swap(c[++a], c[b]);
    }
  }
  swap(c[a+1], c[end]);
  return a+1;
}

void Quicksort(Course c[10], int start, int end) //will sort the new array
{
  int index;
  if (start >= end)
  {
    return;
  }

  index = Partition(c, start, end);  
  Quicksort(c, start, index-1);
  Quicksort(c, index+1, end);
}

void Array(Course c[10])
{
  int ID;
  int coursecredit;
  string sname;

  ifstream ifs("final.txt");

  for(int i = 0; i<10; i++)
  {
    ifs >> ID >> sname >> coursecredit;
    c[i] = Course(ID, sname, coursecredit);
  }
  ifs.close();
}

int main()  //drives previous functions
{
  Course c[10];
  Array(c);
  Print(c);
  cout << endl;
  Quicksort(c, 0, 10-1);
  cout << "Your new array: " << endl;
  Print(c);
  return 0;
}


