// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1e9

using namespace std;

int n, m;
int graph[501][501];

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < 501; i++)
		fill(graph[i], graph[i] + 501, INF);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				graph[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] != INF || graph[j][i] != INF)
				cnt += 1;
		}
		if (cnt == n)
			result += 1;
	}

	cout << result << '\n';
}