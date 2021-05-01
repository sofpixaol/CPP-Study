#include <string>
#include <vector>

class Item
{
  std::string name;
  std::string desc;
 public:
  Item();
  Item(std::string n, std::string d);
  void show();
};
class Box
{
  std::string name;
  std::vector<Item> items;
 public:
  Box();
  Box(std::string n);
  ~Box();
  void show();
  void add(Item &t);
  Box operator+(Box &b);
};
