// 경쟁적 전염
// 입력 : N((크기), K(바이러스 종류)
//		  N개의 줄에 걸쳐 시험관 정보
//		  S(시간), X,Y(위치)
// 출력 : X, Y의 바이러스 종류, 없으면 0
#include <iostream>
#include <vector>

using namespace std;

int n, k, s, x, y;
int matrix[201][201];
vector<pair<int, int>> virus[1000];

int mx[4] = { -1, 0, 1, 0 };
int my[4] = { 0, -1, 0, 1 };

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			matrix[i][j] = temp;
			if (temp != 0)
				virus[temp].push_back({ i, j });
		}
	}

	cin >> s >> x >> y;

	for (int i = 0; i < s; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			vector<pair<int, int>> temp;
			for (int c = 0; c < virus[j].size(); c++)
			{
				for (int a = 0; a < 4; a++)
				{
					int nx = mx[a] + virus[j][c].first;
					int ny = my[a] + virus[j][c].second;
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
					{
						if (matrix[nx][ny] == 0)
						{
							matrix[nx][ny] = j;
							temp.push_back({ nx, ny });
						}
					}
				}
			}
			virus[j].clear();
			for (int c = 0; c < temp.size(); c++)
				virus[j].push_back({ temp[c].first, temp[c].second });
		}
	}

	cout << matrix[x][y] << '\n';
	return 0;
}