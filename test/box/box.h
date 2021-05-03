#include <string>
#include <vector>

class Item
{
  std::string name;
  std::string desc;
 public:
  Item();
  Item(std::string n, std::string d);
  friend std::ostream& operator<<(std::ostream &os, Item &i);
};
class Box
{
  std::string name;
  std::vector<Item> items;
 public:
  Box();
  Box(std::string n);
  ~Box();
  void add(Item &t);
  Box operator+(Box &b);
  friend std::ostream& operator<<(std::ostream &os, Box &b);
};
