//Hello.cpp | A test program
//At 2020.4.25
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "项目一:\n";
    int apples;//声明变量"apples",用于储存苹果数量
    cout << "Man: How many apples do you have?\n";
    cout << "(please enter a number here)\n";
    cin >> apples;//让用户键入数字作为苹果数量
    cout << "Me: Oh,I have " << apples << " apples now.\n";
    cout << "Man: Look,here are two more.\n";
    apples = apples + 2;//苹果数增加两个
    cout << "Man: Now you have " << apples << " apples\n";
    cout << "--------------------------------------------\n";
    system("pause");
    cout << endl;
    cout << "项目二\n";
    double area;//声明变量"area",储存开方前的数
    cout << "输入被开方数\n";
    cin >> area;//让用户键入被开方数
    double side;//声明变量"side"储存开方后的数
    side = sqrt(area);//调用cmath中的sqrt函数进行开平方
    cout << "开方结果为" << side << endl;
    cout << "--------------------------------------------\n";
    system("pause");
    cout << endl;
    cout << "项目三\n";
    cout << "Please enter the password here\n";
    cout << "password:______\b\b\b\b\b\b";//利用\b回退符实现在下划线上输入密码的效果
    int password;//声明变量"password",储存于验证密码正误
    cin >> password;//让用户键入密码
    cout << "\nYour password is " << password << "...\n";
    if (password == 123456)//判断密码是否为123456,如果正确:
    {
        cout << "Password correct\n";//输出"密码正确"
    }
    else//如果错误
    {
        cout << "Password error\n";//输出密码错误
    }
    cout << "--------------------------------------------\n";
    system("pause");
    cout << endl;
    cout << "项目四\n";
    cout << "营销号生成器:\n";
    string a1;
    string a2;
    string a3;
    cout << "对象:";
    cin >> a1;
    cout << endl;
    cout << "行为:";
    cin >> a2;
    cout << endl;
    cout << "原因:";
    cin >> a3;
    cout << "成功生成,请勾选复制:\n";
    cout << a1 << a2 << "是怎么回事呢？"
        << a1 << "相信大家都很熟悉，但"
        << a1 << a2 << "是怎么回事呢，这是我们都关心的问题。下面就让小编带大家一起了解一下，"
        << a1 << "为什么" << a2 << "。"
        << a1 << a2 << "其实就是因为" << a3
        << "，大家可能会很惊讶" << a1 << "怎么会" << a2
        << "呢？但事实就是这样，小编也感到非常惊讶。看完这段网友表示难以置信。以上就是关于"
        << a1 << a2 << "的全部内容了，大家有什么想法呢？欢迎在评论区告诉小编一起讨论哦！\n";
    cout << "--------------------------------------------\n";
    system("pause");
    cout << endl;
    return 0;//返回值为0,说明该程序已正常运行
}
