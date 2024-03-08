// fast campus 강의
// https://www.acmicpc.net/problem/12100
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<vector<int>> rotate90(vector<vector<int>> b)
{
	vector<vector<int>> new_board(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			new_board[j][N - i - 1] = b[i][j];
	return new_board;
}

vector<int> convert(vector<int> lst)
{
	vector<int> new_list1, new_list2;
	for (auto x : lst)
		if (x)
			new_list1.push_back(x);
	for (int i = 1; i < new_list1.size(); i++) {
		if (new_list1[i - 1] == new_list1[i]) {
			new_list1[i - 1] *= 2;
			new_list1[i] = 0;
		}
	}

	for (auto x : new_list1)
		if (x)
			new_list2.push_back(x);
	for (int i = 0; new_list2.size() != N; i++)
		new_list2.push_back(0);
	return new_list2;
}

int dfs(vector<vector<int>> b, int cnt)
{
	int ret = 0;
	for (int i = 0; i < N * N; i++)
		ret = max(ret, b[i / N][i % N]);
	if (cnt == 5)
		return ret;

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> x(N);
		for (int j = 0; j < N; j++)
			x[j] = convert(b[j]);
		if (b != x)
			ret = max(ret, dfs(x, cnt + 1));
		b = rotate90(b);
	}
	return ret;
}

int main()
{
	cin >> N;
	vector<vector<int>> b(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> b[i][j];

	cout << dfs(b, 0);
}