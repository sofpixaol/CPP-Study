#include <iostream>
//来自大佬(命令助手群偶遇)q号117597131
//一个通过引用使a,b的值交换的函数
void exc(int &a, int &b)
{
int temp;
temp = b;
b = a;
a = temp;
}
int main()
{
  int val1 = 10, val2 = 20;
  std::cout << " val1 :" << val1
            << " val2: " << val2
            << '\n';
  exc(val1,val2);
  std::cout << " val1 :" << val1
            << " val2: " << val2
            << '\n';
}
