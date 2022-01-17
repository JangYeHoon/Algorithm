// fast campus 강의
// https://www.acmicpc.net/problem/9663
// 1

#include <iostream>

using namespace std;

int N, result, queen[15];

bool is_available(int row)
{
	for (int r = 0; r < row; r++)
		if (queen[row] == queen[r] || abs(queen[row] - queen[r]) == row - r)
			return false;
	return true;
}

void dfs(int row)
{
	if (row == N)
		result++;
	else {
		for (int col = 0; col < N; col++) {
			queen[row] = col;
			if (is_available(row))
				dfs(row + 1);
		}
	}
}

int main()
{
	cin >> N;
	
	dfs(0);
	cout << result;
}