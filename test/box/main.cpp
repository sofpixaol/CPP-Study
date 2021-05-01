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
  box1.show();
  box2.show();
  box1 = box1 + box2;
  box1.show();
  return 0;
}
