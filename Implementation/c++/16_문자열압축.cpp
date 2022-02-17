// 이것이 취업을 위한 코딩테스트다 325p
// https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 999999;
	int k = 1;
	for (int k = 1; k <= s.size() / 2 + 1; k++)
	{
		string prev = s.substr(0, k);
		string result;
		int count = 1;
		for (int i = k; i < s.size(); i += k)
		{
			if (prev.compare(s.substr(i, k)) == 0)
				count += 1;
			else
			{
				if (count == 1)
					result += prev;
				else
					result += to_string(count) + prev;
				prev = s.substr(i, k);
				count = 1;
			}
		}
		if (count == 1)
			result += prev;
		else
			result += to_string(count) + prev;
		if (answer > result.size())
			answer = result.size();
	}
	return answer;
}

int main()
{
	cout << solution("a") << '\n';
}