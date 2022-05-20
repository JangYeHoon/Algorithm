// fast campus 강의
// https://www.acmicpc.net/problem/17406
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, result = 1e9;
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, -1, 0, 1 };

int chk_sum(vector<int> chk) {
	int ret = 0;
	for (int i = 0; i < chk.size(); i++)
		ret += chk[i];
	return ret;
}

int find_min_arr(vector<vector<int>> arr) {
	int ret = 1e9;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < M; j++)
			tmp += arr[i][j];
		ret = min(tmp, ret);
	}
	return ret;
}

vector<vector<int>> convert(vector<vector<int>> arr, vector<int> qry) {
	int r = qry[0], c = qry[1], s = qry[2];
	r--; c--;
	vector<vector<int>> ret = arr;
	for (int d = 1; d < s + 1; d++) {
		int px = r - d;
		int py = c + d;
		for (int i = 0; i < 4; i++) {
			for (int dd = 0; dd < d * 2; dd++) {
				int nx = px + mx[i];
				int ny = py + my[i];
				ret[nx][ny] = arr[px][py];
				px = nx;
				py = ny;
			}
		}
	}
	return ret;
}

void dfs(vector<vector<int>> arr, vector<vector<int>> q, vector<int> chk) {
	if (chk_sum(chk) == K) {
		result = min(result, find_min_arr(arr));
		return;
	}
	for (int i = 0; i < K; i++) {
		if (chk[i])
			continue;
		vector<vector<int>> new_arr = convert(arr, q[i]);
		chk[i] = 1;
		dfs(new_arr, q, chk);
		chk[i] = 0;
	}
}

int main() {
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	vector<vector<int>> Q(K, vector<int>(3));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++)
			cin >> Q[i][j];
	}

	dfs(A, Q, vector<int>(K));
	cout << result;
}