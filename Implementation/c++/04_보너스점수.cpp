// fast campus 강의
// https://www.acmicpc.net/problem/17389
// 1

#include <iostream>

using namespace std;

int main()
{
	string s;
	int N;
	cin >> N;
	cin >> s;

	int result = 0, bouns = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X')
			bouns = 0;
		else {
			result += i + 1 + bouns;
			bouns++;
		}
	}

	cout << result;
}