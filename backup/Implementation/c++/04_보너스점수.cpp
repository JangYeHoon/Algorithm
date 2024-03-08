// fast campus 강의
// https://www.acmicpc.net/problem/17389
// 2

#include <iostream>

using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;

	int result = 0, bonus = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'O')
			result += i + 1 + bonus++;
		else
			bonus = 0;
	}
	cout << result;
}