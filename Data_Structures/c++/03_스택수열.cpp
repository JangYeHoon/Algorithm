// fast campus 강의
// https://www.acmicpc.net/problem/1874
// 2

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	stack<int> s;
	vector<char> result;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		while (tmp >= cnt) {
			s.push(cnt++);
			result.push_back('+');
		}

		if (tmp == s.top()) {
			s.pop();
			result.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (auto i : result)
		cout << i << '\n';
}