#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

typedef vector<double> dv; //偷懒awa，定义dv为vector<double>类型
typedef double n;//同上偷懒，定义n(number)为double类型
dv data;//定义一个dv(vector<double>)类型的对象用来储存数据
typedef decltype(data.size()) in;//依旧偷懒，定义in为和data.size()返回值相同的类型，用于表示下标(index)

n sum(const dv& d);
n median(const dv& d);
dv mode(const dv& d);
n anova(const dv& d);
ostream& operator<<(ostream& os,const dv& d);
//函数原型，依次为 求和、求中位数、求众数、求方差、输出
n max(const dv& d) {
  return d.back();//将数据按从小到大排序后，最后一个数便是最大值
}
n min(const dv& d) {
  return d.front();//同理，第一个数就是最小值
}
n avg(const dv& d) {
  return sum(d) / d.size();//用求和函数求出数据总合，再除以数据个数
}
//内联函数，依次为 最大值、最小值、平均值
int main() {
  while (1) {//不会停的循环
    n x = 0;//用于输入
    data.clear();//输入前先清空数据
    cin.clear();//清空cin的状态
    while(cin >> x) {
      data.push_back(x);
    }//循环输入n值至x并将x添加到data向量末尾
    cout << endl << "Raw: ";
    for (const auto&t : data)
      cout << t << " ";
    //输出原始数据
    cout << endl;

    sort(data.begin(),data.end());
    cout << "Sorted: ";
    cout << data;//输出排序后的数据和其他属性
  }
  return 0;
}

n sum(const dv& d) {
  n s = 0;
  for (const auto& a : d)
    s += a;
  //依次将d中的每一个数据加到变量s里
  return s;
}
n median(const dv& d) {
  in sz = d.size();//定义sz，sz值为d中元素的个数
  if (sz % 2 == 1) {//如果d中元素个数为基数
    return d[(sz+1)/2-1];//返回d中第(sz+1)/2-1个元素
  } else {
    return (d[sz/2] + d[sz/2-1])/2;//返回d中第sz/2和sz/2-1个元素的平均值
  }
}//注意「序数词」是从0开始数.
dv mode(const dv& d) {
  unsigned t = 1, tmax = 2;
  dv m;
  for (in n = 0; n != (d.size() - 1); n++) {
    if (d[n] == d[n+1]) {
      t++;
    } else t = 1;
    if (t > tmax) {
      tmax = t;
      m.clear();
      m.push_back(d[n]);
    } else if (t == tmax) {
      m.push_back(d[n]);
    }
  }
  return m;
}//...
n anova(const dv& d) {
  n v = avg(d);//定义变量v，v的值为d的平均数
  n ss = 0;//定义变量ss用来存储平方和
  for (const auto& t : d)
    ss += (t-v)*(t-v);//将ss依次与d中的每一个数据和v(平均值)的差平方后相加
  return ss/d.size();//返回平方和除以d中元素的个数
}
ostream& operator<<(ostream& os,const dv& d) {
  for (const auto&t : d)
    os << t << " ";
  os << endl
     << "Size: " << d.size() << endl
     << "Sum: " << sum(d) << endl
     << "Avg: " << avg(d) << endl
     << "Min: " << min(d) << " Max: " << max(d) << endl
     << "Median: " << median(d) <<endl
     <<"Mode: ";
  for (const auto&t : mode(d))
    os << t << " ";
  os << endl
     << "Anova: " << anova(d) << endl;
  return os;
}//用来输出..
