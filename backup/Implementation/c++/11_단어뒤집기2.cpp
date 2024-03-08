// fast campus 강의
// https://www.acmicpc.net/problem/17413
// 2

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	string s, result, tmp;
	getline(cin, s);

	bool tag_chk = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (tag_chk)
				result += s[i];
			else {
				reverse(tmp.begin(), tmp.end());
				result += tmp + ' ';
				tmp = "";
			}
		}
		else if (s[i] == '>') {
			result += '>';
			tag_chk = false;
		}
		else if (s[i] == '<') {
			reverse(tmp.begin(), tmp.end());
			result += tmp + '<';
			tmp = "";
			tag_chk = true;
		}
		else {
			if (tag_chk) result += s[i];
			else tmp += s[i];
		}
	}
	reverse(tmp.begin(), tmp.end());
	result += tmp;
	cout << result;
}