#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

//My Own
int numof0InFactorial(int n) //���ˣ�ֻ�����������������5�����ӣ�Ӧ��Ҫ��1-n������
{
	int res = 0;
	while ((++res) * 5 <= n) {}

	return --res;
}

int numof0InFactorial1(int n)
{
	int ret = 0;
	for (int i = 1; i <= n; i++) //����1-n��ÿһ����
	{
		int j = i;
		while (j % 5 == 0)//������һ������5�����ӵ�����
		{
			ret++;
			j /= 5;
		}
	}
	return ret;
}

int numof0InFactorial2(int n)
{
	int ret = 0;
	while (n)
	{
		ret += n / 5; //ÿ�ε�ǰn/5���ǵ�ǰ�ܹ�������5�����ӵ���Ŀ������nһ��ʼ����30,��һ�־���5,10,15,20,25,30,�ṩ6��5,Ȼ����Щ��ȫ������5������1...6��ֻ��5�����ṩ5
		n /= 5;
	}
}

int main()
{
	assert(numof0InFactorial1(4) == 0);
	assert(numof0InFactorial1(5) == 1);
	assert(numof0InFactorial1(10) == 2);
	assert(numof0InFactorial1(20) == 4);
	assert(numof0InFactorial1(30) == 7);

	return 0;
}