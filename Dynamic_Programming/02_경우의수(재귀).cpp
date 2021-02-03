// 경우의 수
// 입력 : 정수 n
// 출력 : n을 1, 2, 3으로 만들 수 있는 경우의 수
#include <iostream>

using namespace std;

int func(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;

	return func(n - 1) + func(n - 2) + func(n - 3);
}

int main()
{
	cout << func(5) << endl;
	return 0;
}