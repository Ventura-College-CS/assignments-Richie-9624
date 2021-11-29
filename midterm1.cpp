#include <iostream>
#include <vector>

using namespace std;

class Student  //student class
{
  private:   //instance members
    int SID;
    string SName;
    double *scores;

  public:  //defualt constructor
    Student()
    {
      SID = 0;
      SName = "";
      scores = nullptr;
    }
        //parameterized constructor
    Student(int i, string name, double *sc)  
    {
      SID = i;
      SName = name;
      scores = sc;
    }

    int getID(){return SID;}  //getters
    string getName(){return SName;}
    double *getScores(){return scores;}
};

template <class T>  //stack class
class Stack
{
  private:  //instance members
    vector<T>pool;

  public:
    Stack()  //defualt constructor
    {
    }

    void push(const T &el)  //pushes elements into the pool
    {
      pool.push_back(el);
    }

    T pop()  //removes and returns the top of the element from the pool
    {
      T res = pool[pool.size() - 1];
      pool.pop_back();
      return res;
    }

    T topEl()  //returns to top of the pool
    {
      return pool[pool.size() - 1];
    }

    bool isEmpty()  //returns the stack if empty
    {
      return pool.size() == 0;
    }

    int size(){return pool.size();}  //returns the size of the stack
};

int main()
{
  //creates 5 student with information
  Student s1(100, "John", new double[3]{10, 20, 30});
  Student s2(101, "Mike", new double[3]{10.2, 20.2, 30.2});
  Student s3(102, "Evan", new double[3]{1, 2, 3});
  Student s4(103, "Jake", new double[3]{20, 80, 90});
  Student s5(104, "Carl", new double[3]{30, 40, 320});

  Stack<Student>st; //creates the stack

 
  st.push(s1);   // pushes the students into the stack
  st.push(s2);
  st.push(s3);
  st.push(s4);
  st.push(s5);

  cout << "Size: " << st.size() << endl; // prints the size of the stack

  while(!st.isEmpty()) // runs the stack until it is empty
  {

  }
}
