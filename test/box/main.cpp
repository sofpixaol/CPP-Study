#include <iostream>
#include <string>
#include <vector>
#include "box.h"
using namespace std;

int main()
{
  Item item1("test","Just for test.");
  Item item2("smile","Nothing special.");
  Box box1("H");
  Box box2("G");
  box1.add(item1);
  box2.add(item2);
  cout << box1 << box2;
  box1 = box1 + box2;
  cout << box1;
  return 0;
}
