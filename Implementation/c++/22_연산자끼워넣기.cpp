// 이것이 취업을 위한 코딩테스트다 349p
// https://www.acmicpc.net/problem/14888
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	vector<int> op;
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++)
			op.push_back(i + 1);
	}
	sort(op.begin(), op.end());

	int min_value = 1e9, max_value = -1e9;
	do {
		int result = A[0];
		for (int i = 1; i < N; i++) {
			if (op[i - 1] == 1)
				result += A[i];
			else if (op[i - 1] == 2)
				result -= A[i];
			else if (op[i - 1] == 3)
				result *= A[i];
			else if (op[i - 1] == 4)
				result /= A[i];
		}
		min_value = min(min_value, result);
		max_value = max(max_value, result);
	} while (next_permutation(op.begin(), op.end()));
	cout << max_value << '\n' << min_value;
}