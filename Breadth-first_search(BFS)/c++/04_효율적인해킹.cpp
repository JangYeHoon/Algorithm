// fast campus 강의
// https://www.acmicpc.net/problem/1325
// 2

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> list[10001];
bool visited[10001];
int N, M;

int bfs(int n)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(n);
    visited[n] = true;

    int cnt = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < list[now].size(); i++) {
            int next = list[now][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        list[b].push_back(a);
    }

    int max = 0;
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        int tmp = bfs(i);
        if (max < tmp) {
            max = tmp;
            result.clear();
            result.push_back(i);
        }
        else if (max == tmp)
            result.push_back(i);
    }

    for (auto r : result)
        cout << r << ' ';
}