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
};

//humans
human god
{
    "god",
    man,
    137,
    999999,
    1,
    10,
};
human zzx
{
    "ZiXing Zhang",
    woman,
    13,
    300000,
    1,
    10,
};
vector<human> humans;

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
  cout << "Now there are " << humans.size() << " living humans\n"
       << "They are: ";
  for (decltype(humans.size()) index = 0; index != humans.size(); index++)
    {
      if (humans[index].alive)
        cout << index << "."<<  humans[index].name << " ";
    }
  cout << endl;
}
void rand_born()//随机出生
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
  man.money = rand() % 9501 + 500;
  man.alive = true;
  man.level = rand() % 10 + 1;

  info(man);

  cout << "Enter it's name: ";
  getline(cin, man.name);

  system("clear");  // For Linux
  //system("cls);  // For Windows
  info(man);
  humans.push_back(man);
}

void born()//手动出生
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
  system("clear");  // For Linux
  //system("cls);  // For Windows
  info(man);
  humans.push_back(man);
}

human kill(human man)
{
  man.alive = false;
  return man;
}
//战力
double powerof(human man)
{
  double power = man.level + man.money / 5000 + man.old / 5;
  return power;
}
//比较
bool compare(human a, human b)
{
  double pa = powerof(a);
  double pb = powerof(b);
  bool result = pa > pb;
  return result;
}
//战斗
human rand_fight(decltype(humans.size()) ina)
{
  //rand
  unsigned seed;
  seed = time(0);
  srand(seed);

  human a = humans[ina];
  decltype(humans.size()) inb = rand() % humans.size();
  while(ina == inb)
    {
      inb = rand() % humans.size();
    }
  human b = humans[inb];

  cout << a.name << "had a fight with " << b.name << " ...\n";
  cout << a.name;
  if (compare(a,b))
    {
      cout << " winned!\n";
      if (a.level <= 10)
        a.level++;
      a.money += b.money / 10;
    } else {
      cout << " lost!\n";
      a.alive = false;
    }
  return a;
}

int main()
{
  //rand
  unsigned seed;
  seed = time(0);
  srand(seed);

  char mode;

  //  humans.push_back(zzx);
  humans.push_back(god);

  do
    {
      world_time++;
      info_all();
      cin.clear();

      while(true)
        {
          cin.clear();
          cout << "Select mode:" << endl;
          cin >> mode;

          if (mode == 'a')
            {
              info_all();
              for (auto &pr : humans)
                {
                  info(pr);
                  cout << endl;
                }
            }
          if (mode == 'r')
            {
              rand_born();
            }
          if (mode == 'n')
            {
              born();
            }
          if (mode == 'f')
            {
              if (humans.size() >= 2)
                {
                  decltype(humans.size()) index;
                  cout << "Enter the fighter's number:\n";
                  cin >> index;
                  humans[index] = rand_fight(index);
                } else {
                  cout << "There are not enough humans!\n";
                }
            }
          if (mode == 'm' | mode == 'e')
            break;
        }
      system("clear"); //For Linux
      //system("cls); //For Windows
    }
  while (mode == 'm');
  return 0;
}
