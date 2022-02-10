// 럭키 스트레이트
// 입력 : 점수(N), N의 자릿수는 항상 짝수 형태
// 출력 : 럭키 스트레이트를 사용할 수 있으면 "LUCKY", 없으면 "READY"
#include <iostream>

using namespace std;

int pos[8];

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		pos[i] = n % 10;
		n = n / 10;
		count = i + 1;
		if (n <= 0)
			break;
	}

	int mid = count / 2;
	int left = 0;
	for (int i = 0; i < mid; i++)
		left += pos[i];
	int right = 0;
	for (int i = mid; i < count; i++)
		right += pos[i];

	if (left == right)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';
	return 0;
}