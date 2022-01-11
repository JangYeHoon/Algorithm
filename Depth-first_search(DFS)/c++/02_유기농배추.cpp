// fast campus 강의
// https://www.acmicpc.net/problem/1012
// 1

#include <iostream>
#include <cstring>

using namespace std;

int matrix[51][51];
bool visited[51][51];
int M, N, K;
int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + mx[i];
        int ny = y + my[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (!visited[nx][ny] && matrix[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        memset(matrix, 0, sizeof(matrix));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> y >> x;
            matrix[x][y] = 1;
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && matrix[i][j]) {
                    result++;
                    dfs(i, j);
                }
            }
        }
        cout << result << '\n';
    }
}