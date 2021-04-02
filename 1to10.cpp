#include <iostream>
int main()
{
  //while型:
  /*
  int sum = 0, val = 1;
  while (val <= 10)
  {
    sum += val;
    std::cout << sum << '\n';
    ++val;
  }
  std::cout << "Sum of 1 to 10 inclusive is "
            << sum << '\n';
  return 0;
  */
  //for型:
  int sum = 0;
  for (int val = 1; val <= 10; ++val)
  {
    sum += val;
  }
  std::cout << "Sum of 1 to 10 inclusive is "
            << sum << '\n';
  return 0;
}
