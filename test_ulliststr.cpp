#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  cout << "in main! " << endl;

  ULListStr ullist;
  ullist.push_back("sup");
  ullist.push_back("er");
  ullist.push_back("cal");
  ullist.push_back("i");
  ullist.push_back("frag");
  ullist.push_back("il");
  ullist.push_back("ist");
  ullist.push_back("ic");
  ullist.push_back("exp");
  ullist.push_back("i");
  ullist.push_back("alo");
  ullist.push_back("doc");
  ullist.push_back("ious");



  cout << "front " << ullist.front() << " back " << ullist.back() << endl;


  cout << "done!" << endl;
}
