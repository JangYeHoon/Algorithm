// 미로 탈출
// 입력 : 미로 세로 N, 가로 M ( 4 <= N, M <= 200)
//		  N개의 줄에는 각각 M개의 정수(0(괴물) 혹은 1) 미로정보, 시작칸과 마지막칸은 항상 1
// 출력 : 최소 이동 칸의 개수

#include <iostream>
#include <queue>
using namespace std;

int m, n;
int matrix[201][201];

int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx + mx[i];
			int ny = dy + my[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (matrix[nx][ny] == 0)
				continue;
			if (matrix[nx][ny] == 1)
			{
				matrix[nx][ny] = matrix[dx][dy] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return matrix[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &matrix[i][j]);
	}

	int result = bfs(0, 0);
	cout << result << '\n';
	return 0;
}