#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>

//�ⷨ1:��������O(N^3)
int MaxSum1(int *arr, int n)
{
	if (arr == nullptr || n <= 0)
		return 0;

	int max = std::numeric_limits<int>::min();

	for (int i = 0; i < n; ++i) //��ÿһ��λ�ÿ�ʼ
	{
		for (int j = i;;) //��ÿһ��λ�ý���,��ʱ��Ϊ��ѭ���ģ����жϻص���ʼλ��Ϊ����
		{
			int curSum = 0;
			for (int k = i;;) //��ǰ��ʼ�ͽ�����������֮��
			{
				curSum += arr[k];
				k = k == n - 1 ? 0 : ++k;
				if (k == j)
					break;
			}
			curSum += i == j ? 0 : arr[j]; //���һ��,�����ʼ�ͽ�������ͬһ���Ų�
			max = i == j ? std::max(max, arr[i]) : max; //�����ͬһ����ʼͬһ�������Ļ��������ֻ������i,i+1,..n-1,i���֣�����һ�������������
			max = std::max(curSum, max);
			j = j == n - 1 ? 0 : ++j;
			if (j == i)
				break;
		}
	}
	return max;
}

//��̬�滮�Ľⷨ:������ԭʼ����Ļ����ϣ����һ�������ǿ�Խ�˵����������A[0]��ͷ����A[n-1]������



int main()
{
	//yxp_utility::RandomHelper::initSeed();
	//int nTestTime = 1000;
	//size_t nArrSize = 10;
	//int min = -100, max = 100;

	//for (int i = 0; i < nTestTime; ++i)
	//{
	//	auto v = yxp_utility::RandomHelper::randomArray(nArrSize, min, max);
	//	yxp_utility::ArrayHelper::printArr(v);
	//	auto res = MaxSum1(&v[0], v.size());
	//	std::cout << res << std::endl;
	//}


	std::vector<int> v = { 10,-30,20 };
	auto res = MaxSum1(&v[0], v.size());
	assert(res == 30);
	std::cout << res << std::endl;

	v = { 10,30,-20 };
	res = MaxSum1(&v[0], v.size());
	assert(res == 40);
	std::cout << res << std::endl;

	v = { -10,30,-20 };
	res = MaxSum1(&v[0], v.size());
	assert(res == 30);
	std::cout << res << std::endl;

	v = { -10,-30,-20 };
	res = MaxSum1(&v[0], v.size());
	assert(res == -10);
	std::cout << res << std::endl;

	return 0;
}