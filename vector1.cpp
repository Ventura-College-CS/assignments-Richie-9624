#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//when running the program, I had to change what was in the .replit file because if i did the command ./a.out it would not run the whole program and stop at when I added the number and not ask if i wanted to delete a number.

void printVector(vector<int>);

int main()
{
  vector<int>::iterator it;
  vector<int> numbers = {10, 13, 5, 7, 25};
  int new_number;

  printVector(numbers);
  sort(numbers.begin(), numbers.end());
  printVector(numbers);

  cout << "what is your new number: ";
  cin >> new_number;
  for(it=numbers.begin(); it<numbers.end(); it++)
  {
    if(*it > new_number )
      break;
  }
  numbers.insert(it, new_number);
  printVector(numbers);

  cout << "number you want to delete: ";
  cin >> new_number;
  for(it=numbers.begin(); it<numbers.end(); it++)
  {
    if(*it == new_number )
      break;
  }
  if(it == numbers.end())
    cout << "number not found in vector\n";
  else
  numbers.erase(it);
  printVector(numbers);

}

void printVector(vector<int> vec)
{
  vector<int>::iterator it;
  for(it=vec.begin(); it<vec.end(); it++)
  cout << *it << "\t";
  cout << endl;
}