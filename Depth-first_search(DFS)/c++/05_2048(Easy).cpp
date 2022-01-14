// fast campus 강의
// https://www.acmicpc.net/problem/12100
// 1

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;

vector<vector<int>> rotate90(vector<vector<int>> b)
{
	vector<vector<int>> nb(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			nb[j][N - i - 1] = b[i][j];
	return nb;
}

vector<int> convert(vector<int> lst)
{
	vector<int> new_list, new_list2;

	// 오른쪽 수와 같으면 합침
	for (auto i : lst)
		if (i)
			new_list.push_back(i);
	for (int i = 1; i < new_list.size(); i++) {
		if (new_list[i - 1] == new_list[i]) {
			new_list[i - 1] *= 2;
			new_list[i] = 0;
		}
	}

	// N으로 길이를 맞춤
	for (auto i : new_list)
		if (i)
			new_list2.push_back(i);
	for (int i = 0; new_list2.size() != N; i++)
		new_list2.push_back(0);
	return new_list2;
}

int dfs(vector<vector<int>> b, int cnt)
{
	int ret = 0;
	for (int i = 0; i < N * N; i++)
		ret = max(ret, b[i / N][i % N]);
	if (!cnt)
		return ret;

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> x(N);
		for (int j = 0; j < N; j++)
			x[j] = convert(b[j]);
		if (x != b)
			ret = max(ret, dfs(x, cnt - 1));
		b = rotate90(b);
	}
	return ret;
}

int main()
{
	cin >> N;
	board.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cout << dfs(board, 5);
}