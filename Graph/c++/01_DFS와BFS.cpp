// fast campus 강의
// https://www.acmicpc.net/problem/1260
// 1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, V;
vector<int> adj[1001];
bool visited[1001];

void dfs(int v) {
    cout << v << ' ';
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]])
            dfs(adj[v][i]);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        cout << a << ' ';
        for (int i = 0; i < adj[a].size(); i++) {
            if (!visited[adj[a][i]]) {
                visited[adj[a][i]] = true;
                q.push(adj[a][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());
    
    dfs(V);
    cout << '\n';

    memset(visited, false, sizeof(visited));
    bfs(V);
}