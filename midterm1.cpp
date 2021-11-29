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
