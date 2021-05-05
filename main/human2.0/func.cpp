#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>//For rand
#include <ctime>//For time
#include "human.h"
using namespace std;

extern vector<human> humans;
human::human()
{
  srand((unsigned)time(NULL));

  cin.get();
  name = "unfinded";
  int temp = rand() % 2;
  sex = humansex(temp);
  old = 0;
  money = rand() % 95001 + 5000;
  alive = true;
  level = rand() % 6 + 1;

  info(*this);

  cout << "Enter it's name: ";
  getline(cin, name);

  info(*this);
  humans.push_back(*this);
}
human(string name_i humansex sex_i, unsigned old_i, double money_i, bool alive_i, unsigned level_i)
{
  name = name_i;
  sex = sex_i;
  old = old_i;
  money = money_i;
  alive = alive_i;
  level = level_i;
  humans.push_back(*this);
}
double human::power()
{
  double power = level + money / 10000 + old / 5;
  return power;
}
bool compare(const human &a, const human &b)
{
  double pa = a.power();
  double pb = b.power();
  bool result = pa > pb;
  return result;
}
