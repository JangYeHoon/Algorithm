// 문자열 뒤집기
// 입력 : 0과 1로만 이루어진 문자열 S
// 출력 : 행동의 최소 횟수
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s[0] - '0';
	int c0 = 0;
	int c1 = 0;
	if (n == 0)
		c1 += 1;
	else
		c0 += 1;
	for (int i = 0; i < s.size() - 1; i++)
	{
		int n1 = s[i] - '0';
		int n2 = s[i + 1] - '0';
		if (n1 != n2)
		{
			if (n2 == 0)
				c1 += 1;
			else
				c0 += 1;
		}
	}

	int result = min(c0, c1);
	cout << result << '\n';
	return 0;
}