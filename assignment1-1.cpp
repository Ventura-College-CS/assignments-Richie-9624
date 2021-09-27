#include <iostream>
#include <fstream>

using namespace std;

struct student{  //defines the struct to store each student info
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

int main()
{
  ifstream ifs;
  ofstream ofs;
  
  student s;

  ifs.open("students.txt");
  ofs.open("students.bin");

  if (ifs.fail())  //prints message if failed to open
  {
    cout << " could not open the file \n ";
    exit(0);
  }
  
  for(int i=0; i<10; i++)  //runs the loop 10 times
  {
    ifs >> s.id;  //reads the current line data into student struct
    ifs >> s.sname;
    ifs >> s.score[0];
    ifs >> s.score[1];
    s.sum = s.score[0] + s.score[1];
    s.avg = s.sum/ 2.0;

    cout << "ID : " << s.id << endl;  //prints student data 
    cout << "Name : " << s.sname << endl;
    cout << "Score 1 : " << s.score[0] << endl;
    cout << "Score 2 : " << s.score[1] << endl;
    cout << "Sum : " << s.sum << endl;
    cout << "average : " << s.avg << endl;
    cout << "---------------------------------" << endl;

    ofs.write( (char *)&s, sizeof(s)); //writes to file
  }
  ifs.close();  //closes both files
  ofs.close();
}