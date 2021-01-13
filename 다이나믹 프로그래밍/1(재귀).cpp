// 1이 되는 과정
// 입력 : 정수 n
// 출력 : 정수 n이 1이 되는 과정을 모두 출력
#include <iostream>

using namespace std;

int func(int n)
{
	cout << n << endl;
	if (n == 1)
		return n;
	if (n % 2 == 1)
		return func(3 * n + 1);
	else
		return func(n / 2);
}

int main()
{
	func(3);
	return 0;
}