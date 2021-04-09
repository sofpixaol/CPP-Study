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
  double money;
  bool alive;
  unsigned level;
};

//humans
human god
{
    "god",
    man,
    137,
    9999999,
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
int info_all(bool s)//输出所有信息
{
  int livings = 0;
  for (auto pr : humans)
    if (pr.alive)
      livings += 1;
  if (s == true)
    {
      cout << "WorldTime: " << world_time << endl;
      cout << "Now there are " << humans.size() << " humans, " << livings << " living humans." << endl
           << "Living humans are: ";
      for (decltype(humans.size()) index = 0; index != humans.size(); index++)
        {
          if (humans[index].alive)
            cout << index << "."<<  humans[index].name << " ";
        }
      cout << endl;
    }
  return livings;
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
  man.money = rand() % 95001 + 5000;
  man.alive = true;
  man.level = rand() % 6 + 1;

  info(man);

  cout << "Enter it's name: ";
  getline(cin, man.name);

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

  info(man);
  humans.push_back(man);
}
//杀死
void kill(decltype(humans.size()) index)
{
  auto iter = humans.begin() + index;
  humans.erase(iter);
  info_all(true);
}
//战力
double powerof(human man)
{
  double power = man.level + man.money / 10000 + man.old / 5;
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
void rand_fight(decltype(humans.size()) ina)
{
  //rand
  unsigned seed;
  seed = time(0);
  srand(seed);

  human &a = humans[ina];
  decltype(humans.size()) inb = rand() % humans.size();
  while(ina == inb | humans[inb].alive == false)//防止打自己或死人
    {
      inb = rand() % humans.size();
    }
  human &b = humans[inb];

  cout << a.name << " had a fight with " << b.name << " ...\n";
  cout << a.name;
  if (compare(a,b))
    {
      cout << " winned!\n";
      if (a.level < 10)
        a.level++;
      a.money += b.money * 7 / 10;
      b.money = b.money * 3 / 10;
      b.alive = false;
    } else {
      cout << " lost!\n";
      b.money += a.money * 7 / 10;
      a.money = a.money * 3 / 10;
      a.alive = false;
    }
}
//New year
void year()
{
  for (auto &p : humans)
    {
      if (p.alive)
        {
          p.old++;

          double dolt = rand() % 100 + 1;
          int delta_money = rand() % (10000 * p.level / 2) + 5000 * p.level / 2;
          p.money += delta_money;
          p.money += dolt / 100;
          delta_money = rand() % 28000 * p.level / 3 + 3000 * p.level / 2;
          p.money -= delta_money;

          int chance = rand() % 9 + 1;
          if (chance == 2)
            {
              cout << "\t\aThis year " << p.name << " had a good luck!" << endl;
              p.money += (20000 * p.level / 2);
              if (p.level < 10)
                p.level ++;
            }

        }
    }
}


int main()
{
  //rand
  unsigned seed;
  seed = time(0);
  srand(seed);

  char mode;

  //humans.push_back(zzx);
  //humans.push_back(god);
  do
    {
      world_time++;
      year();
      info_all(true);

      do
        {
          cin.clear();
          cout << "Select mode: ";
          cin >> mode;
          cout << endl;

          switch (mode)
            {
            case 'a' :
              info_all(true);
              for (auto &pr : humans)
                {
                  info(pr);
                  cout << endl;
                }
              break;

            case 'r' :
              rand_born();
              break;

            case 'n' :
              born();
              break;

            case 'f' :
              if (info_all(false) >= 2)
                {
                  info_all(true);
                  decltype(humans.size()) index;
                  cout << "Enter the fighter's number:\n";
                  cin >> index;
                  rand_fight(index);
                } else {
                cout << "There are not enough humans!\n";
              }
              break;

            case 'k' :
              if (mode == 'k')
                {
                  info_all(true);
                  decltype(humans.size()) index;
                  cout << "Enter the number of human who you want to kill\n";
                  cin >> index;
                  kill(index);
                }
              break;

            case 'm' :
            case 'e' : break;
            default :
              cout << "Unknown mode" << endl;
              break;
            }
        } while (mode != 'm' && mode != 'e');

      cout << endl;
    }
  while (mode != 'e');
  cout << '\a' << endl;
  return 0;
}
