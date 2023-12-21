#include"stack-application.h"

int cope_(string a)
{
	stack<char> s_oper;
	stack<int> s_number;
	int len = a.length();
	s_oper.push('(');
	int i = 0;
	while (i < len)
	{
		if (a[i] == ' ')
		{
			i++;
			continue;
		}
		int cases = judge(a[i]);
		if (cases == error)
		{
			cout << "�޷������ļ�" << endl;
			return 0;
		}
		else if (cases == number)
		{
			int cope_number = 0;
			while (judge(a[i]) == number)
			{
				cope_number = 10 * cope_number + (a[i] - '0');
				i++;
			}
			s_number.push(cope_number);
			i--;
		}
		else
		{
			char temp = a[i];
			int cmp = compare(temp, s_oper.top());
			if (cmp == high) // �����㼶��ϸߣ�ֱ�ӷ���ջ֮��
			{
				s_oper.push(temp);
			}
			else
			{
				//��ʼ����֮ǰ�ļ���
				do {
					char oper = s_oper.top();//������
					s_oper.pop();
					if (oper != '(' && oper != ')') //�ų�����
					{
						int a = s_number.top();
						s_number.pop();
						int b = s_number.top();
						s_number.pop();
						s_number.push(Calculate(oper, b, a));
					}
					cmp = compare(temp, s_oper.top());
				} while (cmp == low || cmp == equal); // һֱ����
				s_oper.push(temp);
			}
		}
		i++;
	}
	//����ʣ��ļ���
	while (s_oper.size() != 1)
	{
		char oper = s_oper.top();//������
		s_oper.pop();
		if (oper != '(' && oper != ')') //�ų�����
		{
			int a = s_number.top();
			s_number.pop();
			int b = s_number.top();
			s_number.pop();
			s_number.push(Calculate(oper, b, a));
		}
	}
	return s_number.top();
}


int compare(char out, char in)
{
	if (out == '(')
	{
		return high;
	}
	if (in == '(')
	{
		return high;
	}
	if (out == ')')
	{
		return low;
	}
	if ((out == '+' || out == '-') && (in == '*' || in == '/'))
	{
		return low;
	}
	if ((out == '*' || out == '/') && (in == '+' || in == '-'))
	{
		return high;
	}
	return equal;
}

int judge(char a)
{
	if (a >= '0' && a <= '9')
	{
		return number;
	}
	else
	{
		if (a == '(' || a == ')' || a == '*' || a == '/' || a == '+' || a == '-')
		{
			return operator;
		}
		else
		{
			return error;
		}
	}
}

int Calculate(char oper, int a, int b)
{
	if (oper == '*')
	{
		return a * b;
	}
	if (oper == '/')
	{
		return a / b;
	}
	if (oper == '+')
	{
		return a + b;
	}
	if (oper == '-')
	{
		return a - b;
	}
}