#define HALF_BITS_LENGTH 4
// ���ֵ�Ǽ���洢��Ԫ���ȵ�һ�룬�����������4bit
#define FULLMASK 255
// ������ֱ�ʾһ��ȫ��bit��mask���ڶ����Ʊ�ʾ�У�����11111111��
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
// ������ʾ��bits��mask���ڶ����Ʊ�ʾ�У�����11110000��
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
// ������ֱ�ʾ��bits��mask���ڶ����Ʊ�ʾ�У�����ʾ00001111��
#define RSET(b, n) (b = ((LMASK & b) ^ n))
// ����꣬��b���ұ����ó�n
#define LSET(b, n) (b = ((RMASK & b) ^ (n << HALF_BITS_LENGTH)))
// ����꣬��b��������ó�n
#define RGET(b) (RMASK & b)
// �����õ�b���ұߵ�ֵ
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)
// �����õ�b����ߵ�ֵ
#define GRIDW 3
// ������ֱ�ʾ��˧�ƶ���Χ���п�ȡ�
#include <stdio.h>
#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b, n) (b = ((LMASK & b) ^ n))
#define LSET(b, n) (b = ((RMASK & b) ^ (n << HALF_BITS_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)
#define GRIDW 3

int main()
{
	unsigned char b;
	for (LSET(b, 1); LGET(b) <= GRIDW * GRIDW; LSET(b, (LGET(b) + 1)))
		for (RSET(b, 1); RGET(b) <= GRIDW * GRIDW; RSET(b, (RGET(b) + 1)))
			if (LGET(b) % GRIDW != RGET(b) % GRIDW)
				printf("A = %d, B = %d\n", LGET(b), RGET(b));


	return 0;
}
