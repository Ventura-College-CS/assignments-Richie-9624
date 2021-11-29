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
  priority_queue<Student, vector<Student>, StudentCompare> pq; 
  //creayes priority queue of students

  //create the scores array for student 1-5
  double *scores1 = new double[5]{72.5, 38.6, 22.8, 34.5, 55.7};
  Student s1(1, "Akon", scores1, 5);
  
  double *scores2 = new double[5]{82.5, 42.7, 85.8, 64, 75};
  Student s2(2, "Evan", scores2, 5);
  
  double *scores3 = new double[5]{80, 48, 45.8, 55, 44.5};
  Student s3(3, "John", scores3, 5);
  
  double *scores4 = new double[5]{51.5, 92.5, 83, 48.5, 66.7};
  Student s4(4, "Arya", scores4, 5);
  
  double *scores5 = new double[5]{57, 98.6, 42.8, 100, 95.2};
  Student s5(5, "Sans", scores5, 5);
 
  pq.push(s1);
  pq.push(s2);
  pq.push(s3);
  pq.push(s4); //push the students to the priority queue
  pq.push(s5);

  //pop the items out of the pq and print the info
  for (int i = 0; i < 5; i++)
  {
    Student s = pq.top();
    s.display(); //display the details of student at top of pq
    pq.pop();    //pop the student
    cout << endl;
  }
  return 0;
}




