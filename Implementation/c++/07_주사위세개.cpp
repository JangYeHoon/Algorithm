// fast campus 강의
// https://www.acmicpc.net/problem/2480
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> dice(3);
	for (int i = 0; i < 3; i++)
		cin >> dice[i];
	sort(dice.begin(), dice.end());

	if (dice[0] == dice[2])
		cout << 10000 + dice[0] * 1000;
	else if ((dice[0] == dice[1]) || (dice[1] == dice[2]))
		cout << 1000 + dice[1] * 100;
	else
		cout << dice[2] * 100;
}