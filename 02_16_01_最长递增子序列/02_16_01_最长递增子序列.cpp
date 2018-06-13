#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPCommon.h>

//�ݹ�汾:
int LISProcess(int *arr, int j);
int LIS(int *arr, int n)
{
	if (arr == nullptr || n <= 0)
		return 0;
	int *dp = new int[n];
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < n; ++i)
	{
		dp[i] = LISProcess(arr, i);
		max = std::max(dp[i], max);
	}
	delete[]dp; //����ֻ�Ǳ���һ�£�û�ã��������������е�ʱ�������õ�
	dp = nullptr;
	return max;
}

//���ڸ�����β��������еĳ���
int LISProcess(int *arr, int end)
{
	if (end == 0) //����Ϊ0��һ������1
		return 1;

	int res = 1;
	for (int i = end - 1; i >= 0; --i) //��֮ǰ��ÿһ����
	{
		if (arr[i] < arr[end]) //��������С�ڵ�ǰ��β����ô���п�����ӽ���
			res = std::max(res, LISProcess(arr, i) + 1);
		else
			res = std::max(1, res);
	}
	return res;
}



//�ⷨ2:��̬�滮,O(N^2)
int LIS2(int *arr, int n)
{
	if (arr == nullptr || n <= 0)
		return 0;

	int *dp = new int[n];
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < n; ++i)
	{
		int curMax = 1; //��ǰ��һ����
		for (int j = i - 1; j >= 0; --j) //����ǰ����������ܲ����γ�IS
			if (arr[i] > arr[j])
				curMax = std::max(curMax, dp[j] + 1);
		dp[i] = curMax;
		max = std::max(dp[i], max);
	}

	delete[]dp;
	dp = nullptr;
	return max;
}

//��ס(����Ϊi������������е����ֵ)����Сֵ����⣬��Ȼ��O(N^2)
int LIS3(const std::vector<int>&arr)
{
	//(����Ϊi������������е����ֵ)����Сֵ
	std::vector<int> maxLenMinVal(arr.size() + 1, arr[0]);
	int curMaxLen = 1; //��ʼ��ʱ�򣬵�һ��λ�ã�����Ϊ1
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i] > maxLenMinVal[curMaxLen])
			maxLenMinVal[++curMaxLen] = arr[i];
		else
		{
			for (size_t j = 1; j <= curMaxLen; ++j)
			{
				if (maxLenMinVal[j] >= arr[i]) //���ڵ�ʱ��һ��Ҫ��ֹѭ��!!!,���������滻��1,3,5,5,...
				{
					maxLenMinVal[j] = arr[i];
					break;
				}
			}
		}
	}
	return curMaxLen;
}

//�ĳɶ����������ҵ�����λ��
int LIS4(const std::vector<int>&arr)
{
	//(����Ϊi������������е����ֵ)����Сֵ
	std::vector<int> maxLenMinVal(arr.size() + 1, arr[0]);
	int curMaxLen = 1; //��ʼ��ʱ�򣬵�һ��λ�ã�����Ϊ1
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i] > maxLenMinVal[curMaxLen])
			maxLenMinVal[++curMaxLen] = arr[i];
		else
		{
			*std::lower_bound(maxLenMinVal.begin() + 1, maxLenMinVal.begin() + curMaxLen + 1, arr[i]) = arr[i];
		}
	}
	return curMaxLen;
}


int main()
{
	int arr[] = { 2,1 ,5 ,3 ,6,4,8 ,9, 7 };
	size_t n = sizeof(arr) / sizeof(arr[0]);
	std::cout << LIS(arr, n) << std::endl;
	std::cout << LIS2(arr, n) << std::endl;
	std::cout << LIS3(std::vector<int>(arr, arr + n)) << std::endl;
	std::cout << LIS4(std::vector<int>(arr, arr + n)) << std::endl;
	yxp_utility::RandomHelper::initSeed();
	int nTestTime = 1000;
	size_t nArrSize = 10;
	int min = 0, max = 100;

	for (int i = 0; i < nTestTime; ++i)
	{
		auto v = yxp_utility::RandomHelper::randomArray(nArrSize, min, max);
		auto res = LIS(&v[0], v.size());
		auto res2 = LIS2(&v[0], v.size());
		auto res3 = LIS3(v);
		auto res4 = LIS4(v);
		assert(res == res2);
		assert(res == res3);
		assert(res == res4);
	}



	return 0;
}