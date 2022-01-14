// 이것이 취업을 위한 코딩테스트다 344p
// https://www.acmicpc.net/problem/18405
// 1

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Virus {
public:
	int index;
	int second;
	int x;
	int y;
	Virus(int index, int second, int x, int y) {
		this->index = index;
		this->second = second;
		this->x = x;
		this->y = y;
	}

	bool operator <(Virus& other) {
		return this->index < other.index;
	}
};

int matrix[201][201];
vector<Virus> viruses;
int N, K, S, X, Y;
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j] != 0)
				viruses.push_back(Virus(matrix[i][j], 0, i, j));
		}
	}
	sort(viruses.begin(), viruses.end());
	queue<Virus> q;
	for (int i = 0; i < viruses.size(); i++)
		q.push(viruses[i]);

	cin >> S >> X >> Y;
	while (!q.empty()) {
		Virus virus = q.front();
		q.pop();

		if (virus.second == S)
			break;
		for (int i = 0; i < 4; i++) {
			int nx = virus.x + mx[i];
			int ny = virus.y + my[i];

			if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
				if (matrix[nx][ny] == 0) {
					matrix[nx][ny] = virus.index;
					q.push(Virus(virus.index, virus.second + 1, nx, ny));
				}
			}
		}
	}
	cout << matrix[X][Y] << '\n';
}