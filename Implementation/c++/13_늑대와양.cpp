// fast campus 강의
// https://www.acmicpc.net/problem/16956
// 1

#include <iostream>

using namespace std;

int R, C;
char matrix[501][501];
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &matrix[i][j]);
			if (matrix[i][j] == '\n')
				scanf("%c", &matrix[i][j]);
		}
	}
	
	bool result_chk = true;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (matrix[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int nx = i + mx[k];
					int ny = j + my[k];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
						continue;
					if (matrix[nx][ny] == 'S')
						result_chk = false;
				}
			}
		}
	}

	if (result_chk) {
		cout << "1\n";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (matrix[i][j] == '.')
					matrix[i][j] = 'D';
				cout << matrix[i][j];
			}
			cout << '\n';
		}
	} else cout << '0';
}