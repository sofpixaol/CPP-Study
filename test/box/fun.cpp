#include <iostream>
#include <string>
#include <vector>
#include "box.h"

using namespace std;

Item::Item(string n, string d)
{
  name = n;
  desc = d;
}
void Item::show()
{
  cout << "Name: " << name << endl;
  cout << "\t" << desc << endl;
}

Box::Box()
{
  name = "New nox";
}
Box::Box(string n)
{
  name = n;
}
Box::~Box()
{
  cout << name << " bye!" << endl;
}
void Box::show()
{
  cout << "The box " << name << " has " << items.size() << " items." << endl;
  cout << "They are :" << endl;
  for (auto &t : items)
    {
      t.show();
    }
}
void Box::add(Item &t)
{
  items.push_back(t);
}
Box Box::operator+(Box &b)
{
  for (auto t : b.items)
    {
      items.push_back(t);
    }
  return *this;
}
