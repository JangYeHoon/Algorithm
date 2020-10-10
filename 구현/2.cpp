// 문자열 재정렬
// 입력 : 문자열(S), 영어 대문자와 숫자(0~9)로 구성
// 출력 : 알파엣 오름차순으로 정렬하여 출력한 뒤에 모든 숫자 더한값 출력
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