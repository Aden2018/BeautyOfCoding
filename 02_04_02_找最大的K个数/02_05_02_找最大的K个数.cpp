#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>

typedef int number;

//�ⷨ1:����Ȼ����


//�ⷨ2:partition,Ȼ����һ�������֣�������������󣬸պþ���kλ�ã���ô���ҵ���,ƽ��:O(NlogK)

//�ⷨ3:ά��һ��K��������С�� , O(N*logK)

bool SmallHeap(int v1, int v2)
{
	return v1 > v2;
}

void PushHeap(std::vector<number> &heap, number val)
{
	heap.push_back(val);
	std::push_heap(heap.begin(), heap.end(), SmallHeap);
}

number PopHeap(std::vector<number> &heap)
{
	std::pop_heap(heap.begin(), heap.end(),SmallHeap);
	number back_save = heap.back();
	heap.pop_back();
	return back_save;
}

std::vector<number> FindKTthLargest(const std::vector<number> &v, number K)
{

	if (v.size() < K)
		throw std::exception("invalid input");
	if (v.size() == K)
		return v;

	std::vector<number> heap;
	std::make_heap(heap.begin(), heap.end(), SmallHeap);

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (heap.size() < K)
		{
			PushHeap(heap, v[i]);
		}
		else
		{
			if (v[i] > heap[0])
			{
				PopHeap(heap);
				PushHeap(heap, v[i]);
			}
		}
	}
	return heap;
}


//�ⷨ4:������ݷ�Χ�Ƚ�С�Ļ����������ֱ��ͼ��Ȼ����ͳ��O(N)

//�ⷨ5:BFPRT

int main()
{
	yxp_utility::RandomHelper::initSeed();
	size_t n = 100;
	number K = 5;
	int min = 10, max = 100;

	auto v = yxp_utility::RandomHelper::randomArray(n, min, max);
	yxp_utility::ArrayHelper::printArr(v);
	auto largestK = FindKTthLargest(v, K);
	yxp_utility::ArrayHelper::printArr(largestK);
	std::sort(largestK.begin(), largestK.end(), SmallHeap);
	yxp_utility::ArrayHelper::printArr(largestK);

	auto v_save = v;
	std::sort(v_save.begin(), v_save.end(),SmallHeap);
	yxp_utility::ArrayHelper::printArr(&v_save[0],K);

	return 0;
}