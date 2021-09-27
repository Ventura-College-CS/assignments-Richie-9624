#include <iostream>
#include <fstream>

using namespace std;

struct student{ //defines the struct to store each student info
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

int main()
{
  ifstream ifs;

  student s;

  ifs.open("students.bin");

 if (ifs.fail())  //prints message if failed to open
  {
    cout << " could not open the file \n ";
    exit(0);
  }

  int ID;
  cout << "enter the ID of the student you want to search: " << endl;
  cin >> ID;

  for(int i=0; i<10; i++)  //runs the loop 10 times
  {
    ifs.read( (char *)&s, sizeof(s));  //reads from the open file

    if (ID==s.id)
    {
      cout << "ID : " << s.id << endl;  
      cout << "Name : " << s.sname << endl;
      cout << "Score 1 : " << s.score[0] << endl;
      cout << "Score 2 : " << s.score[1] << endl;
      cout << "Sum : " << s.sum << endl;
      cout << "average : " << s.avg << endl;
    }
  }
  ifs.close();
  return(0);
}