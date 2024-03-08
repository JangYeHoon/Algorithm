// fast campus 강의
// https://www.acmicpc.net/problem/5397
// 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		vector<char> left;
		vector<char> right;
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '>') {
				if (!right.empty()) {
					left.push_back(right.back());
					right.pop_back();
				}
			}
			else if (s[i] == '<') {
				if (!left.empty()) {
					right.push_back(left.back());
					left.pop_back();
				}
			}
			else if (s[i] == '-') {
				if (!left.empty())
					left.pop_back();
			}
			else
				left.push_back(s[i]);
		}

		while (!left.empty()) {
			right.push_back(left.back());
			left.pop_back();
		}
		reverse(right.begin(), right.end());

		for (auto r : right)
			cout << r;
		cout << '\n';
	}
}