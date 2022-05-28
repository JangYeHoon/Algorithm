// 이것이 취업을 위한 코딩테스트다 259p
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, X, K;
int graph[101][101];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = 1e9;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cin >> X >> K;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}

	int result = graph[1][K] + graph[K][X];
	if (result == 1e9)
		cout << -1;
	else
		cout << result;
}