// fast campus 강의
// https://www.acmicpc.net/problem/1012
// 2

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, N, M, K;
int matrix[51][51];
bool visited[51][51];
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
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

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = px + mx[i];
            int ny = py + my[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (!visited[nx][ny] && matrix[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(matrix, 0, sizeof(matrix));
        memset(visited, false, sizeof(visited));

        cin >> N >> M >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            matrix[x][y] = 1;
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && matrix[i][j]) {
                    result += 1;
                    dfs(i, j);
                }
            }
        }
        cout << result << '\n';
    }
}