//getline.cpp : 无聊..
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
  string str;
  getline(cin, str);
  for(auto iter = str.begin(); iter != str.end() && !isspace (*iter); ++iter)
    {
      *iter = toupper(*iter);
    }
  cout << str << endl;
  return 0;
}
