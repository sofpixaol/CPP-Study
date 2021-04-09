//tom.cpp
#include <iostream>
#include <string>
#include <unistd.h>//For usleep
#include <cstdlib>//For rand
#include <ctime>//For time
using namespace std;

//World Variables
enum humansex {man,woman};
int world_time = 0;

struct human
{
  string name;
  humansex sex;
  unsigned old;
  int money;
  bool alive;

};

//humans
human tom
{
  "Tom",
  man,
  21,
  10000,
  true,
};

void info(human man)
{
  const string m = "man", w = "woman";
  string rs;
  if (man.sex == 0)
  {
    rs = m;
  } else {
    rs = w;
  }
  cout << "Name: " << man.name << endl
       << "Sex: " << rs << endl
       << "Old: " << man.old << endl
       << "Money: " << man.money << endl
       << "Alive: " << man.alive << endl;
}
int main()
{
  //rand
  unsigned seed;
  seed = time(0);
  srand(seed);
  //Story about Tom
  info(tom);
  while (tom.alive)
  {
    //usleep(250000);
    usleep(500000);
    world_time++;
    //    if (world_time % 12 == 0)
    //  {
      tom.old++;
      tom.money += rand() % 5000 + 1500;
      tom.money -= rand() % 4500 + 2000;
      system("clear");
      //system("cls");
      //For windows
    //  }
    if (tom.money <= 0)
    {
        cout << "* Oh...I have no money...[Tom]\n";
        tom.alive = false;
    }
    if (tom.old >= 85)
    {
       cout << "(* Tom is too old...)\n";
       tom.alive = false;
    }
    info(tom);
  }
  return 0;
}
