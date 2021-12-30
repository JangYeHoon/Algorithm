// fast campus 강의
// https://www.acmicpc.net/problem/1697
// 1

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int bfs(int n, int k)
{
    queue<int> q;
    int cost[MAX] = {0, };
    q.push(n);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == k)
            return cost[now];
        
        int next = now - 1;
        if (0 <= next && next < MAX && !cost[next]) {
            cost[next] = cost[now] + 1;
            q.push(next);
        }

        next = now + 1;
        if (0 <= next && next < MAX && !cost[next]) {
            cost[next] = cost[now] + 1;
            q.push(next);
        }

        next = now * 2;
        if (0 <= next && next < MAX && !cost[next]) {
            cost[next] = cost[now] + 1;
            q.push(next);
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << bfs(N, K);
}