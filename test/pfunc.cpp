#include <iostream>
using namespace std;

void say1(unsigned times)
{
  for (unsigned i = 0; i < times; i++)
    {
      cout << i << " !" << endl;
    }
}
void say2(unsigned times)
{
  for (unsigned i = 0; i < times; i++)
    {
      cout << ' ' << i << '\n';
    }
  cout << endl;
}
void say(int times,void (*pf)(unsigned times))
{
  pf(times);
}
int main()
{
  say1(7);
  say2(3);
  say(7,say2);
  return 0;
}
