// 이것이 취업을 위한 코딩테스트다 321p
// https://www.acmicpc.net/problem/18406
// 2

#include <iostream>

using namespace std;

int main()
{
	string str;
	int result = 0;

	cin >> str;

	for (int i = 0; i < str.size() / 2; i++)
		result += str[i] - '0';

	for (int i = str.size() / 2; i < str.size(); i++)
		result -= str[i] - '0';

	if (result == 0) cout << "LUCKY";
	else cout << "READY";
}