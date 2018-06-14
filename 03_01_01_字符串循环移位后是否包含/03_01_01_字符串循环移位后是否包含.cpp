#include <iostream>
#include <string>
#include <algorithm>

//�ⷨ1:ִ��ѭ����λȻ���ж�


//�ⷨ2:������Ӻ����ѭ����λ�����еĿ�����
bool IsSubStrOfCycleShift(const std::string&str1, const std::string& str2)
{
	if (str2.length() == 0 || str2.length() > str1.length())
		return false;
	std::string twice = str1 + str1;
	return twice.find(str2, 0) == -1 ? false : true;
}


int main()
{
	std::string str1 = "AABCD";
	std::string str2 = "DAAB";
	std::string str3 = "DAABC";

	std::cout << std::boolalpha << IsSubStrOfCycleShift(str1, str2) << std::endl;
	std::cout << std::boolalpha << IsSubStrOfCycleShift(str1, str3) << std::endl;
	std::cout << std::boolalpha << IsSubStrOfCycleShift(str1, "DABC") << std::endl;

	return 0;
}
