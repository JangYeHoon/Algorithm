// 이것이 취업을 위한 코딩테스트다 349p
// https://www.acmicpc.net/problem/14888
// 1

#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[12], min_value = 1e9, max_value = -1e9, add, sub, mul, divi;

void dfs(int idx, int num)
{
	if (idx + 1 == N) {
		min_value = min(min_value, num);
		max_value = max(max_value, num);
	}
	else {
		if (add > 0) {
			add--;
			dfs(idx + 1, num + arr[idx + 1]);
			add++;
		}
		if (sub > 0) {
			sub--;
			dfs(idx + 1, num - arr[idx + 1]);
			sub++;
		}
		if (mul > 0) {
			mul--;
			dfs(idx + 1, num * arr[idx + 1]);
			mul++;
		}
		if (divi > 0) {
			divi--;
			dfs(idx + 1, num / arr[idx + 1]);
			divi++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> add >> sub >> mul >> divi;

	dfs(0, arr[0]);
	cout << max_value << '\n' << min_value;
}