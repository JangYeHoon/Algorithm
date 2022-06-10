// fast campus 강의
// https://www.acmicpc.net/problem/7490
// 1

#include <iostream>
#include <vector>

using namespace std;

int N;

void calculate(int n, int result, vector<char> v) {
	if (n == N) {
		if (result == 0) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i];
			cout << '\n';
		}
		return;
	}

	vector<char> v1 = v;
	v1.push_back(' ');
	v1.push_back(n + 1 + '0');
	if (v.size() > 2) {
		int op_tmp = v.size() - 2;
		if (v[op_tmp] == '+')
			calculate(n + 1, result - n + (10 * n + (n + 1)), v1);
		else if (v[op_tmp] == '-')
			calculate(n + 1, result + n - (10 * n + (n + 1)), v1);
	}
	else calculate(n + 1, 12, v1);

	vector<char> v2 = v;
	v2.push_back('+');
	v2.push_back(n + 1 + '0');
	calculate(n + 1, result + n + 1, v2);

	vector<char> v3 = v;
	v3.push_back('-');
	v3.push_back(n + 1 + '0');
	calculate(n + 1, result - n - 1, v3);
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		vector<char> v;
		v.push_back('1');

		calculate(1, 1, v);
		cout << '\n';
	}
}