//human.cpp
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>//For usleep
#include <cstdlib>//For rand
#include <ctime>//For time
using namespace std;

//World Variables
enum humansex {man,woman};
int world_time = 0;

//define human
struct human
{
  string name;
  humansex sex;
  unsigned old;
  int money;
  bool alive;
  unsigned level;
  bool r;
};

//humans
const human god
{
    "god",
    man,
    137,
    999999,
    1,
    10,
    false
};
human zzx
{
    "ZiXing Zhang",
    woman,
    13,
    300000,
    1,
    10,
    true
};
human humans[5] = {zzx,god,god,god,god};
decltype(sizeof(humans)) human_num = 1;

//functions
void info(human man)//输出一个人的信息
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
       << "Alive: " << man.alive << endl
       << "Level: " << man.level << endl;
}
void info_all()//输出所有信息
{
  cout << "WorldTime: " << world_time << endl;
  cout << "Now there are " << human_num << " humans.\n"
       << "They are: ";
  for (auto &pr : humans)
    {
      if (pr.r)
        cout << pr.name << " ";
    }
  cout << endl;
}
void rand_born()//随机出生
{
  if (human_num != sizeof(humans))
    {
      //rand
      unsigned seed;
      seed = time(0);
      srand(seed);

      human man;
      cin.get();
      man.name = "unfinded";
      int temp = rand() % 2;
      man.sex = humansex(temp);
      man.old = 0;
      man.money = rand() % 9500 + 500;
      man.alive = true;
      man.level = rand() % 9 + 1;
      man.r = true;

      info(man);

      cout << "Enter it's name: ";
      getline(cin, man.name);

      system("clear");  // For Linux
      //system("cls);  // For Windows
      info(man);
      humans[human_num] = man;
      human_num++;
    } else {
    cout << "Humans_num is full!\n";
  }
}

void born()//手动出生
{
  if (human_num != sizeof(humans))
    {
      human man;

      cin.get();
      cout << "\nEnter it's name(string): ";
      getline(cin, man.name);

      int temp_sex;
      cout << "\nEnter it's sex(0-man,1-woman): ";
      cin >> temp_sex;
      man.sex = humansex(temp_sex);

      cout << "\nEnter it's old(int): ";
      cin >> man.old;

      cout << "\nEnter it's money(unsiged): ";
      cin >> man.money;

      man.alive = true;

      cin.clear();
      cout << "\nEnter it's level(1-10): ";
      unsigned temp_level;
      while (cin >> temp_level)
        {
          if (temp_level <= 10 && temp_level >= 1)
            man.level = temp_level;
          else
            cout << "Please enter a number from 1 to 10!\n";
        }
      man.r = true;
      system("clear");  // For Linux
      //system("cls);  // For Windows
      info(man);
      humans[human_num] = man;
      human_num++;
    } else {
  cout << "Humans_num is full!\n" << endl;
  }
}
int main()
{
  //rand
  unsigned seed;
  seed = time(0);
  srand(seed);

  while(true)
    {
      world_time++;
      info_all();
      int mode;
      cin.clear();
      cin >> mode;
      if (mode == 1)
        rand_born();
      if (mode == 2)
        born();
      if (mode == 3)
        for (auto &pr : humans)
  	  {
            if (pr.r)
              info(pr);
	  }
      if (mode == 4)
        break;
      system("clear"); //For Linux
      //system("cls); //For Windows
    }
  return 0;
}
