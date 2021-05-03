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

ostream& operator<<(ostream &os, Item &t)
{
  os << "Name: " << t.name << endl;
  os << '\t' << t.desc << endl;
  return os;
}
Box::Box()
{
  name = "New box";
}
Box::Box(string n)
{
  name = n;
}
Box::~Box()
{
  cout << name << " bye!" << endl;
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
ostream& operator<<(ostream &os, Box &b)
{
  os << "The box " << b.name << " has " << b.items.size() << " items." << endl;
  os << "They are :" << endl;
  for (auto &t : b.items)
    {
      os << t;
    }
  return os;
}
