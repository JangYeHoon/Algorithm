// 이것이 취업을 위한 코딩테스트다 322p
//
// 2

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s, result = "";
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			sum += s[i] - '0';
		else
			result += s[i];
	}
	sort(result.begin(), result.end());
	if (sum != 0)
		result += to_string(sum);
	cout << result;
}