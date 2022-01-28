// 이것이 취업을 위한 코딩테스트다 349p
// https://www.acmicpc.net/problem/14888
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N, A[101], add, sub, mul, divi, max_value = -1e9, min_value = 1e9;

void dfs(int idx, int num)
{
	if (idx == N) {
		max_value = max(max_value, num);
		min_value = min(min_value, num);
	}
	else {
		if (add > 0) {
			add--;
			dfs(idx + 1, num + A[idx]);
			add++;
		}
		if (sub > 0) {
			sub--;
			dfs(idx + 1, num - A[idx]);
			sub++;
		}
		if (mul > 0) {
			mul--;
			dfs(idx + 1, num * A[idx]);
			mul++;
		}
		if (divi > 0) {
			divi--;
			dfs(idx + 1, num / A[idx]);
			divi++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> add >> sub >> mul >> divi;

	dfs(1, A[0]);
	cout << max_value << '\n' << min_value;
}