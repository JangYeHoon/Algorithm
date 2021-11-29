// fast campus 강의
// https://www.acmicpc.net/problem/5397
// 1
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		string s;
		stack<char> front;
		stack<char> back;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '<' && !front.empty()) {
				back.push(front.top());
				front.pop();
			}
			else if (s[i] == '>' && !back.empty()) {
				front.push(back.top());
				back.pop();
			}
			else if (s[i] == '-' && !front.empty())
				front.pop();
			else
				front.push(s[i]);
		}

		vector<char> result;
		while (!back.empty()) {
			front.push(back.top());
			back.pop();
		}
		while (!front.empty()) {
			result.push_back(front.top());
			front.pop();
		}
		
		reverse(result.begin(), result.end());
		for (auto i : result)
			cout << i;
		cout << '\n';
	}
}