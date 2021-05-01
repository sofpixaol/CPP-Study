#include <iostream>
#include <string>
using namespace std;

enum Boxsize {l,m,s};
struct Box
{
  unsigned Id;
  string Name;
  string Desc;
  Boxsize Size;
};

Box Test
{
  137,
  "Test",
  "A box for test.",
  l,
};
Box New
{
  1024,
  "Mew",
  "A new box.",
  s,
};

void Show(const Box &B)
{
  cout << B.Id << endl << " " << B.Size;
  cout << "Name: " << B.Name << endl;
  cout << "\t" << B.Desc << endl;
}
template <typename T>
void Swap(T &a, T &b)
{
  T temp;
  temp = a;
  a = b;
  b = temp;
}
template<> void Swap<Box>(Box &a, Box &b)
{
  Box temp;
  temp.Name = a.Name;
  temp.Desc = a.Desc;
  temp.Size = a.Size;

  a.Name = b.Name;
  a.Desc = b.Desc;
  a.Size = b.Size;

  b.Name = temp.Name;
  b.Desc = temp.Desc;
  b.Size = temp.Size;
}
int main()
{
  //Swap two box.
  Show(Test);
  Show(New);
  Swap(Test,New);
  Show(Test);
  Show(New);
  //Swap two double.
  double d1, d2;
  d1 = 1.37;
  d2 = 1.024;
  cout << d1 << endl << d2 << endl;
  Swap(d1, d2);
  cout << d1 << endl << d2 << endl;
  return 0;
}
