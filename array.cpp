#include <iostream>
#include <string>
using namespace std;
int main()
{
  if(0)
  {
    unsigned int scores[11] = {};
    unsigned grade;
    while (cin >> grade)
    {
      if (grade <= 100) {
        ++scores[grade/10];
      }
    }
    for(auto i : scores)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
  if(1)
  {
    constexpr size_t sz = 5;
    int arr[sz] = {1,2,3,4,5};
    int *ip = arr;//等价于int *ip = &arr[0];
    int *ip2 = arr + 4;//指向arr的尾元素
    int *ip3 = arr + sz;//指向arr的尾元素的下一位置
    cout << *ip << ' ' << *ip2 << ' ' << *ip3 << endl;
  }
  return 0;
}
