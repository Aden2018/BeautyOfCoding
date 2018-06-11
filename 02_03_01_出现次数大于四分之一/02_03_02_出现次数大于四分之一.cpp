//������:

//////////////////////////////////////////////////////////////////////////
//�ҵ������г���Ƶ�ʴ���1/4��������Ȼ�����������ֻ��3��
//˼�룺ÿ��ɾȥ4����ͬ���������ʣ�������Ϊ��ѡ�Ĵ𰸣����Ҫ����ѡ�����ִ������
//////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

#define ARRAY_SIZE 15
#define RESULT_NUM 3 //�����г���Ƶ�ʵĴ���1/(RESULT_NUM+1)
int gl_array[ARRAY_SIZE] = { 1,2,1,4,1,4,2,9,1,7,4,3,9,4,3 };//���������ּ���

struct Result
{
	int iNumber;
	int iTempTimes;
};

int GetEmptyElemInResult(Result r[], int iArrayLength)
{
	int i = 0;
	for (i = 0; i < iArrayLength; i++)
	{
		if (r[i].iTempTimes <= 0)
		{
			return i;
		}
	}
	return -1;
}

int GetNumberPosInResult(int iNumber, Result r[], int iArrayLength)
{
	int i = 0;
	for (i = 0; i < iArrayLength; i++)
	{
		if (r[i].iNumber == iNumber && r[i].iTempTimes > 0)
		{//iNumber�����ں�ѡ�У�������Ч���ڸ��������ּ����У����ִ�������0��
			return i;
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	Result resultArray[RESULT_NUM];//�����ѡ����
	int i, j, iTemp;
	for (i = 0; i < RESULT_NUM; i++)
	{
		resultArray[i].iNumber = 0;
		resultArray[i].iTempTimes = 0;
	}
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		iTemp = GetNumberPosInResult(gl_array[i], resultArray, RESULT_NUM);
		if (-1 != iTemp)
		{//����ǰ�������ں�ѡ�����У�����Ч��������ִ���+1
			++resultArray[iTemp].iTempTimes;
		}
		else//���ں�ѡ��
		{
			iTemp = GetEmptyElemInResult(resultArray, RESULT_NUM);
			if (-1 != iTemp)
			{//�����ѡ����RESULT_NUM��Ԫ�أ�����ǰ�������ں�ѡ������
				resultArray[iTemp].iNumber = gl_array[i];
				resultArray[iTemp].iTempTimes = 1;
			}
			else
			{//û�п�λ�ˣ����ҵ�ǰ�����ѡ�����е�����Ԫ�ض�����ͬ��ִ�С�ɾ��������
				for (j = 0; j < RESULT_NUM; j++)
				{
					--resultArray[j].iTempTimes;
				}
			}
		}
	}

	//test the result in the array
	for (i = 0; i < RESULT_NUM; i++)
	{
		if (resultArray[i].iTempTimes > 0)
		{
			iTemp = 0;
			for (j = 0; j < ARRAY_SIZE; j++)
			{
				if (resultArray[i].iNumber == gl_array[j])
				{
					++iTemp;
				}
			}
			if (iTemp > ARRAY_SIZE / (RESULT_NUM + 1))//���ִ���������ֵ
			{
				cout << resultArray[i].iNumber << ": " << iTemp << endl;
			}
		}
	}
	return 0;
}