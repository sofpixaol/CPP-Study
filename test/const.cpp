#include <iostream>
int main()
{
  int i = 1;//int型变量
  const int c = 3;//int型常量 顶层常量
  int &ri = i;//i引用
  const int &rc = c;//c常量引用
  int* pi = &i;//指向i的指针
  const int* pc = &c;//指向常量c的指针 底层常量
  const int* const cpc = &c;//指向常量c的常量指针 既是顶层常量又是底层常量
  std::cout << " i: " << i
            << " c: " << c
            << " ri: " << ri
            << " rc: " << rc
            << " *pi: " << *pi
            << " *pc: " << *pc
            << " *cpc: " << *cpc
            << '\n';
  i = 137;
  // c = 1024; 错误 常量不可重新赋值
  std::cout << " i: " << i
            << " c: " << c
            << " ri: " << ri
            << " rc: " << rc
            << " *pi: " << *pi
            << " *pc: " << *pc
            << " *cpc: " << *cpc
            << '\n';
  *pi = 10;
  // *pc = 1024; 错误 指针指向一个常量 常量不可重新赋值
  pc = nullptr;
  // cpc = nullptr; 错误 常量指针不可修改指向的地址
  std::cout << " i: " << i
            << " c: " << c
            << " ri: " << ri
            << " rc: " << rc
            << " *pi: " << *pi
            // << " *pc: " << *pc
            //脑子又抽了awa
            << " pc: " << pc
            << " *cpc: " << *cpc
            << '\n';
  return 0;
}
