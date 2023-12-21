#include"calculate.h"

int main()
{
	cout << "输入运算表达式:" << endl;
	string target;
	cin >> target;
	int x = cope_(target);
	cout << x;
	return 0;
}
