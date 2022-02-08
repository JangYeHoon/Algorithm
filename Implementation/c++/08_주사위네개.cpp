// fast campus 강의
// https://www.acmicpc.net/problem/2484
// 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, result = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> dice(4);
		for (int j = 0; j < 4; j++)
			cin >> dice[j];
		sort(dice.begin(), dice.end());

		int cnt = 0;
		if (dice[0] == dice[3])
			cnt = 50000 + dice[0] * 5000;
		else if ((dice[0] == dice[1] && dice[1] == dice[2]) || (dice[1] == dice[2] && dice[2] == dice[3]))
			cnt = 10000 + dice[1] * 1000;
		else if (dice[0] == dice[1] && dice[2] == dice[3])
			cnt = 2000 + dice[1] * 500 + dice[2] * 500;
		else if ((dice[0] == dice[1]) || (dice[1] == dice[2]))
			cnt = 1000 + dice[1] * 100;
		else if (dice[2] == dice[3])
			cnt = 1000 + dice[2] * 100;
		else
			cnt = dice[3] * 100;

		result = max(result, cnt);
	}

	cout << result;
}