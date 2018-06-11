#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <random>

unsigned int gcd1(unsigned int x, unsigned int y)
{
	return (y == 0) ? x : gcd1(y, x%y);
}


//����������������⣬������y==1,x�ϴ�(�����������%10000)��ʱ�򣬻�һֱÿ�μ�һ�ݹ飬��ɶ�ջ���
unsigned int gcd2(unsigned int x, unsigned int y)
{
	if (x < y)
		return gcd2(y, x);
	if (y == 0)
		return x;
	else
		return gcd2(x - y, y);
}


int main()
{
	std::srand(0);
	std::default_random_engine e;
	for (int i = 0; i < 10000; ++i)
	{
		unsigned int num1 = e()%1000, num2 = e()% 1000;
		assert(gcd1(num1, num2) == gcd2(num1, num2));
		//gcd1(num1, num2);
		//gcd2(num1, num2);
	}




	return 0;
}