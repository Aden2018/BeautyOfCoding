#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

typedef int Type;

//������Ȼ����n/2λ�ã�һ�����ǳ��ִ�������һ���
Type Find1(Type* arr, int n) 
{

}

//
Type Find(Type* ID, int N)
{
	Type candidate;
	int nTimes, i;
	for (i = nTimes = 0; i < N; i++)
	{
		if (nTimes == 0)
		{
			candidate = ID[i], nTimes = 1;
		}
		else
		{
			if (candidate == ID[i])
				nTimes++;
			else
				nTimes--;
		}
	}
	return candidate;
}


int main()
{


	return 0;
}