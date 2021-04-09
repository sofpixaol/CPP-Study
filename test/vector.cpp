#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
int main()
{
  vector<string> text;//储存字符串元素的向量
  string word;//储存用户输入的单词
  while(cin >> word)
  {
    text.push_back(word);//将用户输入的单词添加到text向量尾部
  }
  for(decltype(text.size()) index = 0; index != text.size(); ++index)
  //依次处理text的每个元素
  {
    string result = text[index];
    for(decltype(result.size()) n = 0; n != result.size(); ++n)
    //依次处理result字符串中的每个字符
    {
      result[n] = toupper(result[n]);//转为大写
    }
    cout << result << endl;//输出结果（并开始处理text的下一个元素
  }
  return 0;
}
