// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/11404
// 1

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int graph[101][101];

int main() {
	cin >> n >> m;

	for (int i = 0; i < 101; i++)
		fill(graph[i], graph[i] + 101, 1e9);

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++)
			if (a == b) graph[a][b] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < graph[a][b])
			graph[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1e9)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}