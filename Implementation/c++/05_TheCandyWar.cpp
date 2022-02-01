// fast campus 강의
// https://www.acmicpc.net/problem/9037
// 1

#include <iostream>

using namespace std;

int C[10];
int T, N;

void candy_plus()
{
	for (int i = 0; i < N; i++)
		if (C[i] % 2 != 0)
			C[i]++;
}

bool candy_chk()
{
	int tmp = C[0];
	for (int i = 1; i < N; i++)
		if (tmp != C[i])
			return true;
	return false;
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> C[i];
		candy_plus();

		int result = 0;
		while (candy_chk()) {
			int tmp_C[10];
			for (int i = 0; i < N; i++)
				tmp_C[i] = C[i];
			for (int i = 1; i <= N; i++)
				C[i % N] = C[i % N] / 2 + tmp_C[i - 1] / 2;
			candy_plus();
			result++;
		}
		cout << result << '\n';
	}
}