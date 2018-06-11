#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

//My Own
int first1posOfFactorial(int n) //ʵ���Ͼ���2�����ӵĸ�������Ϊ������1���֣�˵������2�ı��� 
{
	int res = 0;
	while (n)
	{
		//res += n / 2;
		//n /= 2;

		n >>= 1;
		res += n;
	}
	return res + 1; //����3�����ұ߶�����1�ڵ����ڶ�λ��res=1
}

int main()
{
	assert(first1posOfFactorial(30) == 27);

	return 0;
}