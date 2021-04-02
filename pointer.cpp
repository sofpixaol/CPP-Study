#include <iostream>
int main()
{
  int mode;
  mode = 3;
  if(mode == 1)
  {
    int i = 137;
    int* pi = &i;//一个指向i的指针
    std::cout << pi;
  }
  if(mode == 2)
  {
    int* pi = nullptr;//一个空指针
    int* np;//一个未初始化的指针
    std::cout << pi << '\n' << np;
  }
  if(mode == 3)
  {
    int i = 137;
    int &ri = i;
    int* pi = &i;
    std::cout << " i: " << i
              << " ri: " << ri
              << " pi: " << pi
              << " *pi: " << *pi
              << '\n';
    ri = 1024;
    std::cout << " i: " << i
              << " ri: " << ri
              << " pi: " << pi
              << " *pi: " << *pi
              << '\n';
    *pi = 32767;
    std::cout << " i: " << i
              << " ri: " << ri
              << " pi: " << pi
              << " *pi: " << *pi
              << '\n';
    pi = 0;
    i = 137;
    std::cout << " i: " << i
              << " ri: " << ri
              << " pi: " << pi
              // << " *pi: " << *pi
              //脑子抽了去打印一个空指针指向的值awa
              << '\n';
  }
  if(mode = 4)
  {
    double obj = 1.37, *pd = &obj;
    void *pv;
    /*
    std::cout << " *pv: " << *pv
              << " pv:" << pv
              << '\n';
    */
    pv = pd;
    /*
    std::cout << " *pv: " << *pv
              << " pv:" << pv
              << '\n';
    */
  }
  return 0;
}
