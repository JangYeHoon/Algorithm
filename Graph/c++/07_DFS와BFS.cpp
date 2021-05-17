#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[1001] = false;
vector<int> adj[1001];

void dfs(int v)
{
    visited[v] = true;
    cout << v << ' ';
    for (int i = 0; i < adj[v].size(); i++)
    {
        y = adj[i][j];
        if (!visited[y])
            dfs(y)
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v)
    while(!q.empty())
    {
        v = q.front()
        q.pop()
        cout << v << ' ';
        for (int i = 0; i < adj[v].size(); i++)
        {
            y = adj[v][i];
            if (!visited[y])
            {
                q.push(y)
                visited[y] = true;
            }
        }
    }
}

int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n + 1; i++)
        adj[i].sort();
    
    dfs(v);
    cout << '\n';
    for (int i = 0; i < n + 1; i++)
        visited[i] = false;
    bfs(v);
}