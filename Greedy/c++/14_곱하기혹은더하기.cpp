// 이것이 취업을 위한 코딩테스트다 312p
// 2

#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	long long result = s[0] - '0';
	for (int i = 1; i < s.size(); i++) {
		int num = s[i] - '0';
		if (num <= 1 || result <= 1)
			result += num;
		else
			result *= num;
	}
	cout << result;
}