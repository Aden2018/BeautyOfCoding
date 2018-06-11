#include <iostream>
#include <algorithm>
#include <vector>

#define INF INT_MAX

//S:����
//C:ÿ�������������
//H:�����
//B:ʵ�ʹ�������

//��̬�滮�汾����ʣ��V����������£���ѡ��0...T-1�����ϣ��ܹ���õ����Ž�
int Cal(int V, int T)
{
	std::vector<std::vector<int>> opt(V + 1, std::vector<int>(T, 0));
	opt[0][T] = 0;                              // �߽�������TΪ������������
	for (int i = 1; i <= V; i++)              // �߽�����
	{
		opt[i][T] = -INF;
	}
	for (int j = T - 1; j >= 0; j--)
	{
		for (int i = 0; i <= V; i++)
		{
			opt[i][j] = -INF;
			for (int k = 0; k <= C[j]; k++) // ������j������ѡȡ����k
			{
				if (i < k * V[j])
					break;

				int x = opt[i - k * V[j]][j + 1];
				if (x != -INF)
				{
					x += H[j] * k;
					if (x > opt[i][j])
					{
						opt[i][j] = x;
					}
				}
			}
		}
	}
	return opt[V][0];
}


//������¼�汾
int[V + 1][T + 1] opt;  	// ������ļ�¼��������i��T�������У�
							// �ҳ������ܺ�ΪV'��һ�����������������ܹ��ﵽ
							// opt��V'��i��T-1�����洢��opt[V'][i]��
							// ��ʼ��ʱopt�д洢ֵΪ-1����ʾ����������δ��⡣
int Cal(int V, int type)
{
	if (type == T)
	{
		if (V == 0)
			return 0;
		else
			return -INF;
	}
	if (V < 0)
		return -INF;
	else if (V == 0)
		return 0;
	else if (opt[V][type] != -1)
		return opt[V][type]; 	// ������������⣬��ֱ�ӷ���������Ľ⣻
								// ��������δ��⣬������������
	int ret = -INF;
	for (int i = 0; i <= C[type]; i++)
	{
		int temp = Cal(V �C i * C[type], type + 1);
		if (temp != -INF)
		{
			temp += H[type] * i;
			if (temp > ret)
				ret = temp;
		}
	}
	return opt[V][type] = ret;
}

//�ⷨ3:̰�Ĳ���
//��Ϊÿ��������2���ݴΣ��ȿ�V%2  �������1�Ǳ���Ҫ��1��С������ ������2^0��������H����
//Ȼ����Ҫ��V-2^0 ��ô�����ϣ�


int main() 
{

}