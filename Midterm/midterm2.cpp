#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Student  //student class
{
  private:   //instance members
    int SID;
    string SName;
    double *scores;
    int numScores; //added variable to store number of scores

  public:  //defualt constructor
    Student()
    {
      SID = 0;
      SName = "";
      scores = nullptr;
      numScores = 0;
    }
        //parameterized constructor
    Student(int i, string name, double *sc, int n)  
    {
      SID = i;
      SName = name;
      scores = sc;
      numScores = n;
    }

    int getID(){return SID;}  //getters
    string getName(){return SName;}
    double *getScores(){return scores;}

    double getsum() //method to get sum of scores
    {
      double sum = 0;
      for(int i = 0; i < numScores; i++) //sum up the scores
      {
        sum += scores[i];
      }
      return sum; //return new sum
    }

    void display() //method to display student info
    {
      cout << "ID: " << getID() << " "
      << "Name: " << getName() << " "
      << "Scores: ";
      for(int i = 0; i < numScores; i++)
      {
        cout << scores[i] << " ";
      }
      cout << "Score sum: " << getsum();
    }
};

class StudentCompare //studentcompare class
{
  public:
  bool operator()(Student s1, Student s2)  //larger sum as higher priority
  {
    return s1.getsum() < s2.getsum();
  }
};

int main()
{
  
}




