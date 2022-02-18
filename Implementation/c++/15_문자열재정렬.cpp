// 이것이 취업을 위한 코딩테스트다 322p
//
// 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string answer;
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) == 0)
			answer += s[i];
		else
			n += (s[i] - '0');
	}
	sort(answer.begin(), answer.end());
	answer += to_string(n);

	cout << answer << '\n';
	return 0;
}