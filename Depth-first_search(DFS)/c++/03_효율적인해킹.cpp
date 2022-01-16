// fast campus 강의
// https://www.acmicpc.net/problem/1325
// 2

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> computer[10001];
bool visited[10001];
int N, M;

int dfs(int x, int cnt)
{
    visited[x] = true;
    for (int i = 0; i < computer[x].size(); i++) {
        int y = computer[x][i];
        if (!visited[y]) {
            cnt++;
            cnt = dfs(y, cnt);
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        computer[y].push_back(x);
    }

    int max_value = -1;
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        int cnt = dfs(i, 0);
        if (max_value < cnt) {
            max_value = cnt;
            result.clear();
            result.push_back(i);
        }
        else if (max_value == cnt)
            result.push_back(i);
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
}