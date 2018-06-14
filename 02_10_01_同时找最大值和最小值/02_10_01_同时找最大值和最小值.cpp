#include <YXPUtility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

//�ⷨ1:ֱ�ӱ���,�Ƚ�2N����Ҫ

//�ⷨ2:����,���ǻ�ı�ԭ���飬�Ƚ�1.5N��
std::vector<int> GetMaxAndMin2(std::vector<int> & arr)
{
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < arr.size(); i += 2)
	{
		if (i == arr.size()) //���������
		{
			min = std::min(min, arr[i]);
			max = std::max(max, arr[i]);
			return{ min,max };
		}
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]); //С�Ľ�����ǰһ��λ��

		min = std::min(min, arr[i]);
		max = std::max(max, arr[i + 1]);
	}
	return{ min,max };
}

//�ⷨ3:������������3/2N
std::vector<int> GetMaxAndMin3(const std::vector<int> & arr)
{
	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < arr.size(); i += 2)
	{
		if (i == arr.size()) //���������
		{
			min = std::min(min, arr[i]);
			max = std::max(max, arr[i]);
			return{ min,max };
		}
		if (arr[i] > arr[i + 1]) //�޸ĳɲ�����
		{
			min = std::min(min, arr[i + 1]);
			max = std::max(max, arr[i]);
		}
		else
		{
			min = std::min(min, arr[i]);
			max = std::max(max, arr[i + 1]);
		}
	}
	return{ min,max };
}

//���η�,����1.5N��
std::vector<int> GetMaxAndMin4(const std::vector<int> & arr, int i, int j)
{
	if (j - i <= 1)
	{
		if (arr[i] < arr[j])
			return{ arr[i],arr[j] };
		else
			return{ arr[j],arr[i] };
	}

	auto left_ret = GetMaxAndMin4(arr, i, i + ((j - i) >> 1));
	auto right_ret = GetMaxAndMin4(arr, i + ((j - i) >> 1) + 1, j);

	int min = std::min(left_ret[0], right_ret[0]);
	int max = std::max(left_ret[1], right_ret[1]);
	return{ min,max };
}


int main()
{
	yxp_utility::RandomHelper::initSeed();
	int nTestTime = 100;
	size_t nArrSize = 10;
	int min = 1, max = 100;

	for (int i = 0; i < nTestTime; ++i)
	{
		auto v = yxp_utility::RandomHelper::randomArray(nArrSize, min, max);
		std::vector<int> comp(2, 0);
		comp[0] = *std::min_element(v.begin(), v.end());
		comp[1] = *std::max_element(v.begin(), v.end());
		auto res2 = GetMaxAndMin2(v);
		auto res3 = GetMaxAndMin3(v);
		auto res4 = GetMaxAndMin4(v, 0, v.size() - 1);
		assert(comp == res2);
		assert(res2 == res3);
		assert(res3 == res4);
	}
	return 0;
}