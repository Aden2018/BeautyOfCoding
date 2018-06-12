#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPCommon.h>

//�ⷨ1:��������O(N^3)
int MaxSum1(int *arr, int n)
{
	if (arr == nullptr || n <= 0)
		return 0;

	int max = std::numeric_limits<int>::min();

	for (int i = 0; i < n; ++i) //��ÿһ��λ�ÿ�ʼ
	{
		for (int j = i; j < n; ++j) //��ÿһ��λ�ý���
		{
			int curSum = 0;
			for (int k = i; k <= j; ++k) //��ǰ��ʼ�ͽ�����������֮��
				curSum += arr[k];
			max = std::max(curSum, max);
		}
	}
	return max;
}

//�ⷨ2:�Ż�һ��O(N^2)
int MaxSum2(int *arr, int n)
{
	if (arr == nullptr || n <= 0)
		return 0;

	int max = std::numeric_limits<int>::min();

	for (int i = 0; i < n; ++i) //��ÿһ��λ�ÿ�ʼ
	{
		int curSum = 0;
		for (int j = i; j < n; ++j) //��ÿһ��λ�ý���
		{
			curSum += arr[j]; //��ʵ�̶��˿�ʼ����β��������飬��һ����ǰһ����֮����һ�����Ĵ�С
			max = std::max(curSum, max);
		}
	}
	return max;
}

//�ⷨ3:����˼�� O(NlogN)
//���3����Խ�����Ӳ��ֵ�ʱ��(A[0]��ʼ��A(n/2)��ʼ�����������֮��)��ô��(�÷���7�ı���һ���ܹ��󵽣��������岻��������)

//�ⷨ4:��̬�滮 �ݹ�汾
void MaxSumProcess4(int *arr, int i, int j, int *allMax, int *startMax);
int MaxSum4(int *arr, int n)
{
	int *allMax = new int[n]; //��ǰλ�õ�n-1λ�÷�Χ�ϵĵ�����������
	int *startMax = new int[n]; //�����Ե�ǰλ�ÿ�ʼ�ĵ�n-1��Χ������������
	MaxSumProcess4(arr, 0, n - 1, allMax, startMax);
	int res = allMax[0];
	delete[]allMax;
	delete[]startMax;
	return res;
}
//��i->jλ�ã���allMax��startMax
void MaxSumProcess4(int *arr, int i, int j, int *allMax, int *startMax) //������Ҫά������dp���飬���ò�������ֵ������
{
	if (i == j)
	{
		startMax[i] = arr[i];
		allMax[i] = arr[i];
		return;
	}

	MaxSumProcess4(arr, i + 1, j, allMax, startMax);
	startMax[i] = std::max(startMax[i + 1] + arr[i], arr[i]);
	allMax[i] = std::max(startMax[i + 1] + arr[i], allMax[i + 1]);
}

//�����汾
int MaxSum5(int *arr, int n)
{
	int *allMax = new int[n]; //��ǰλ�õ�n-1λ�÷�Χ�ϵĵ�����������
	int *startMax = new int[n]; //�����Ե�ǰλ�ÿ�ʼ�ĵ�n-1��Χ������������
	allMax[n - 1] = arr[n - 1];
	startMax[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		startMax[i] = std::max(startMax[i + 1] + arr[i], arr[i]);
		//allMax[i] = std::max(startMax[i + 1] + arr[i], allMax[i + 1]);
		allMax[i] = std::max(startMax[i], allMax[i + 1]); //����Ҳ������
	}
	int res = allMax[0];
	delete[]allMax;
	delete[]startMax;
	return res;
}

//�����汾,�ռ��Ż�
int MaxSum6(int *arr, int n)
{
	int nStartMax = arr[n - 1];
	int nAllMax = arr[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		nStartMax = std::max(nStartMax + arr[i], arr[i]);
		nAllMax = std::max(nStartMax, nAllMax); //�����һ��������nStartMax������
	}
	return nAllMax;
}

//���գ���������ƽʱ�����İ汾��
int MaxSum7(int *arr, int n)
{
	int curMax = 0;
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < n; ++i)
	{
		curMax += arr[i];
		max = std::max(max, curMax);
		curMax = curMax < 0 ? 0 : curMax;
	}
	return max;
}


int main()
{
	yxp_utility::RandomHelper::initSeed();
	int nTestTime = 1000;
	size_t nArrSize = 100;
	int min = -100, max = 100;

	for (int i = 0; i < nTestTime; ++i)
	{
		auto v = yxp_utility::RandomHelper::randomArray(nArrSize, min, max);
		auto res = MaxSum1(&v[0], v.size());
		auto res2 = MaxSum2(&v[0], v.size());
		auto res4 = MaxSum4(&v[0], v.size());
		auto res5 = MaxSum5(&v[0], v.size());
		auto res6 = MaxSum6(&v[0], v.size());
		auto res7 = MaxSum7(&v[0], v.size());
		assert(res == res2);
		assert(res4 == res2);
		assert(res5 == res2);
		assert(res6 == res2);
		assert(res7 == res2);
	}

	return 0;
}