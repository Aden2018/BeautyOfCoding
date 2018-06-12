#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPCommon.h>

//�ⷨ1:ö�������Ӿ��� O(N^2*M^2*M*N)
int max(int x, int y)
{
	return (x > y) ? x : y;  // ���ڱȽ�x��y�Ĵ�С������x��y�еĽϴ���
}

// @parameters
// A����ά����
// n������
// m������

int Sum(int * A, int rows, int cols, int i_min, int i_max, int j_min, int j_max)
{
	int sum = 0;
	for (int i = i_min; i <= i_max; ++i)
	{
		for (int j = j_min; j <= j_max; ++j)
		{
			sum += A[i*cols + j];
		}
	}
	return sum; //not implemented
}

int MaxSum1(int* A, int rows, int cols)
{
	int maximum = std::numeric_limits<int>::min();
	for (int i_min = 0; i_min < rows; i_min++)
		for (int i_max = i_min; i_max < rows; i_max++)
			for (int j_min = 0; j_min < cols; j_min++)
				for (int j_max = j_min; j_max < cols; j_max++)
					maximum = max(maximum, Sum(A, rows, cols, i_min, i_max, j_min,
						j_max));
	return maximum;
}

//�ⷨ2:�Ѽ��㵽�ĺʹ�����,���Ǵ�ģ�û�ĳ������ܶ�߽�������������ʵ������������ܸ���
int MaxSum2(int* A, int rows, int cols)
{
	int max = std::numeric_limits<int>::min();
	//���ɱ߽���Ϣ����,PS[I][J] ��ʾ��0,0��i,jλ���Ӿ���ĺ�
	std::vector<std::vector<int>> PS(rows, std::vector<int>(cols, 0));
	PS[0][0] = A[0];
	for (int i = 1; i < rows; ++i)
		PS[i][0] = PS[i - 1][0] + A[i*cols];
	for (int j = 1; j < cols; ++j)
		PS[0][j] = PS[0][j - 1] + A[j];
	for (int i = 1; i < rows; ++i)
		for (int j = 1; j < cols; ++j)
			PS[i][j] = PS[i - 1][j] + PS[j - 1][i] - PS[i - 1][j - 1] + A[i*cols + j];

	//���ݱ߽���Ϣ����ÿ�������飬��O(1)ʱ�������
	for (int lu_row = 0; lu_row < rows; ++lu_row)
		for (int lu_col = 0; lu_col < cols; ++lu_col) //���Ͻ�
			for (int rb_row = lu_row; rb_row < rows; ++rb_row)
				for (int rb_col = lu_col; rb_col < cols; ++rb_col) //���½�
				{
					int tmp;
					if (rb_col == lu_col && rb_row == lu_row)
						tmp = PS[rb_row][rb_col];
					else if (lu_row == 0) //����ı߽������������⣬�������
						tmp = PS[rb_row][rb_col] - PS[rb_row][lu_col - 1];
					else if (lu_col == 0)
						tmp = PS[rb_row][rb_col] - PS[lu_row - 1][rb_col];
					else
						tmp = PS[rb_row][rb_col] - PS[lu_row - 1][rb_col]
						- PS[rb_row][lu_col - 1] + PS[lu_row - 1][lu_col - 1];
					max = std::max(tmp, max);
				}

	return max;
}

//�ⷨ3:����ÿ�п�ʼ��ÿ�н�β�ģ�Ȼ��Ϳ���ת����һά�����
int MaxSumOfRow(int *arr, int n);
int MaxSum3(int* A, int rows, int cols)
{
	int max = std::numeric_limits<int>::min();
	int *rowSum = new int[cols]();
	for (int i = 0; i < rows; ++i)
	{
		memcpy(rowSum, A + i*cols, sizeof(int)*cols);
		//���յ�ǰ��һ�У���������
		int tmp = MaxSumOfRow(rowSum, cols);
		max = std::max(tmp, max);
		for (int j = i + 1; j < rows; ++j) //���µ��н���
		{
			for (int k = 0; k < cols; ++k)
				rowSum[k] += A[j*cols + k];
			tmp = MaxSumOfRow(rowSum, cols);
			max = std::max(tmp, max);
		}
	}
	return max;
}

//����02_14_01���������������
int MaxSumOfRow(int *arr, int n)
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
	size_t rows = 10, cols = 10;
	int min = -10, max = 10;

	for (int i = 0; i < nTestTime; ++i)
	{
		int * mat = new int[rows*cols];
		yxp_utility::RandomHelper::randomMatrix(mat, rows, cols, min, max);
		auto res = MaxSum1(mat, rows, cols);
		auto res2 = MaxSum2(mat, rows, cols);
		auto res3 = MaxSum3(mat, rows, cols);
		//std::cout << res << std::endl;
		assert(res == res3);
		//assert(res == res2); //����2ûд����
	}



	return 0;
}