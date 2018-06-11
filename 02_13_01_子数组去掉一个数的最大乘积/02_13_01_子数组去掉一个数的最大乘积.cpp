#include  <YXPCommon.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <numeric>

//�����ⷨ:
long long GetMaxProduct(const std::vector<int> &arr)
{
	long long res = std::numeric_limits<int>::min();
	for (size_t i = 0; i < arr.size(); ++i)
	{
		long long tmp = 1;
		auto arr_cp = arr;
		for (size_t j = 0; j < arr.size(); ++j)
		{
			if (j != i)
				tmp *= arr[j];
		}
		res = std::max(tmp, res);
	}
	return res;
}

//�ⷨ1:û����������˵������ⷨ����O(N^2)

//�ⷨ2:ͨ���������ж�


long long CalcProduct(const std::vector<int> &arr)
{
	long long res = 1;
	std::for_each(arr.begin(), arr.end(), [&res](int val) { if (val) res *= val; });
	return res;
}


long long GetMaxProduct2(std::vector<int> &arr)
{
	int neg_num = 0, zero_num = 0, pos_num = 0;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == 0)
			++zero_num;
		else if (arr[i] > 0)
			++pos_num;
		else 
			++neg_num;
	}

	if (zero_num >= 2) //����0������ôȥ������0
		return 0;
	else if (zero_num == 1)
	{
		if ((neg_num & 1) == 0) //ż��������
		{
			//��ô����ȥ�����0��ֱ����˵õ����ֵ
			arr.erase(std::find(arr.begin(), arr.end(), 0));
		}
		else //��������������ô��ֻ��ȥ���������
		{
			return 0; //ȥ�������ͻ���һ��0
		}
	}
	else //û��0
	{
		if ((neg_num & 1) == 0) //ż����������û��0
		{
			if (pos_num > 0) //���ȱ�֤��������ģ����ȥ������ֵ��С������
			{
				int min_pos = std::numeric_limits<int>::max();
				for (size_t i = 0; i < arr.size(); ++i)
				{
					if (arr[i] > 0)
						min_pos = std::min(min_pos, arr[i]);
				}
				arr.erase(std::find(arr.begin(), arr.end(), min_pos));
			}
			else //û����������ôֻ��ȥ������ֵ���ĸ�����
			{
				int max_neg = std::numeric_limits<int>::max();
				for (size_t i = 0; i < arr.size(); ++i)
				{
					if (arr[i] < 0) //��������С�ĸ���
						max_neg = std::min(max_neg, arr[i]);
				}
				arr.erase(std::find(arr.begin(), arr.end(), max_neg));
			}
		}
		else //��������������ô��ȥ������ֵ��С�ĸ���
		{
			int min_neg = std::numeric_limits<int>::min();
			for (size_t i = 0; i < arr.size(); ++i)
			{
				if (arr[i] < 0) //���������ĸ���
					min_neg = std::max(min_neg, arr[i]);
			}
			arr.erase(std::find(arr.begin(), arr.end(), min_neg));
		}
	}
	return CalcProduct(arr);
}



int main()
{

	yxp_utility::RandomHelper::initSeed();
	int nTestTime = 1000;
	size_t nArrSize = 10;
	int min = -10, max = 10;

	for (int i = 0; i < nTestTime; ++i)
	{
		auto v = yxp_utility::RandomHelper::randomArray(nArrSize, min, max);
		auto res = GetMaxProduct(v);
		auto res2 = GetMaxProduct2(v);
		assert(res == res2);
	}

	return 0;
}