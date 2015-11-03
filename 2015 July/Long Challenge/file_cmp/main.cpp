#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
  string line1, line2;
  ifstream f1 ("..\\brute_force_out.txt");
  ifstream f2("..\\lazy_out.txt");
  if (f1.is_open() && f2.is_open())
  {
    int line_num = 1;
    while ( getline (f1,line1) )
    {
        getline(f2,line2);
        if( line1 != line2)
        {
            cout << "line " << line_num << endl;
            cout << line1 << endl;
            cout << line2 << endl;
            cout << endl;
        }
        line_num++;
    }
    f1.close();
    f2.close();
  }

  
}
