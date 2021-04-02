#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	const bool F = false;
	const bool T = true;
	int ti = T;
	int fi = F;
	cout << "True: " << ti << endl
			 << "False: " << fi << endl;
	int val = sqrt(pow(36,2)+pow(48,2));
	cout << val << endl;
//137,0x89,0b10001001,0211
	int v1 = T & F;
	int v2 = T | F;
	int v3 = T ^ F;
	int v4 = 0b1 << 1;
	cout << v1 << endl
			 << v2 << endl
			 << v3 << endl
			 << v4 << endl;
	return 0;
}
