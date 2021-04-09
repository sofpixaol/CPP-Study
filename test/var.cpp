#include <iostream>
int main()
{
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << '\n';//32
  std::cout << u - u2 << '\n';//x
  //运行后得详细值4294967264

  int i = 10, i2 = 42;
  std::cout << i2 - i << '\n';//32
  std::cout << i - i2 << '\n';//-32
  std::cout << i - u << '\n';//0
  std::cout << u - i << '\n';//0
}
