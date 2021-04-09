#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
  int mode = 3;
  if (mode == 1)//模式一：利用送代器实现讲string中的字符转为大写
  {
    string s("test for iterator");
    for (auto iter = s.begin(); iter != s.end()/* && !isspace(*iter)*/; ++iter)//自动定义常量送代器且确保有意义，然后指向下一个元素
    {
      *iter = toupper(*iter);//转大写
    }
    cout << s << endl;//输出
  }
  if (mode == 2)//模式二：利用常量送代器输出vector中的每一个string元素
  {
    vector<string> text {"Hello","Hi","Hey ya","Henlo","Howdy",""};
    for (auto iter = text.cbegin(); iter != text.cend() && !iter-> empty(); ++iter)//自动定义常量送代器且确保有意义，然后指向下一个元素
    {
      cout << *iter << endl;//输出
    }
  }
  if (mode == 3)//模式三：利用送代器将向量中的每个整数元素平方后输出
  {
    vector<int> num{2,3,4,2,1,4,3,2,5,7};//定义向量num，含有十个整数元素
    for (auto iter = num.begin(); iter != num.end(); ++iter)//自动定义常量送代器且确保有意义，然后指向下一个元素
    {
      *iter *= *iter;//将送代器所指的元素乘方
      cout << *iter << ' ';//输出
    }
  }
  return 0;
}
