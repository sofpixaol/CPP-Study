#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
int main()
{
  int mode = 4;
  if(mode==1)//模式一：将字符串中的字符全部转为'X'
  {
    string s("homework");
    for(auto &c : s)//自动定义对字符串s中每个字符的引用
    {
      c = 'X';//将该字符改为X
    }
    cout << s;
  }
  if(mode==2)//模式二：将字符串中的第一个单词转为大写
  {
    string s("hello world");
    for(decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    //定义和字符串s的大小相同类型的变量index为0作为下标，当下标不等于(不超过)字符串s的大小并且字符串s中该位置不是空格时，将index加一(处理下一个字符)
    {
      s[index] = toupper(s[index]);//将字符串s中该字符转为大写
    }
    cout << s;
  }
  if(mode==3)//模式三：去掉字符串中的标点后输出
  {
    string s("hello,world!!");
    string result;
    for(decltype(s.size()) index = 0; index !=s.size(); ++index)//略
    {
      if(!ispunct(s[index]))//如果字符串s中该字符不为标点符号
      {
        result += s[index];//将这个字符添加到字符串result中
      }
    }
    cout << result;
  }
  if(mode==4)//模式四：利用string下标将输入的十进制数字转为十六进制
  {
    const string HEX("123456789ABCDEF");//定义十六进制的字符串
    string result;//储存结果
    string::size_type n;//储存输入的数
    while(cin >> n)
    {
      if(n<HEX.size())//排除无效数值
      {
        result += HEX[n];//将对应的十六进制字符添加到result字符串中
      }
    }
    cout << result;
  }
  return 0;
}