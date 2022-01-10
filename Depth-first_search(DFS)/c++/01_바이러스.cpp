// fast campus 강의
// https://www.acmicpc.net/problem/2606
// 1

#include <iostream>
#include <vector>

using namespace std;

vector<int> virus[101];
bool visited[101];
int N, M, count;

void dfs(int x)
{
    visited[x] = true;
    for (int i = 0; i < virus[x].size(); i++) {
        int y = virus[x][i];
        if (!visited[y]) {
            count++;
            dfs(y);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        virus[x].push_back(y);
        virus[y].push_back(x);
    }

    dfs(1);
    cout << count;
}