#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <>

//�ⷨ1:�������� O(N^2)


//�ⷨ2:������Ȼ�����ÿһ����arr[i]�����ж��ֲ���sum-arr[i]����������
std::vector<int> GetTwoNumOfSum2(std::vector<int> & arr, int aim)
{
	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (std::binary_search(arr.begin(), arr.end(), aim - arr[i])) //��Ȼ������û�п���aim=16,��������������8�����
			return{ arr[i],aim - arr[i] };
	}
	return{ -1,-1 };
}

//�ⷨ3:��ϣ������

//�ⷨ4:������Ȼ��˫ָ�뷨
std::vector<int> GetTwoNumOfSum4(std::vector<int> & arr, int aim)
{
	std::sort(arr.begin(), arr.end());
	int left = 0, right = arr.size() - 1;
	while (left < right)
	{
		if (arr[left] + arr[right] == aim)
			return{ arr[left],arr[right] };
		else if (arr[left] + arr[right] < aim)
			++left;
		else
			--right;
	}
	return{ -1,-1 };
}






int main()
{


	return 0;
}