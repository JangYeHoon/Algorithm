// fast campus 강의
// https://www.acmicpc.net/problem/1766
// 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int in_degree[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> N >> M;
    vector<vector<int>> arr(N + 1);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0)
            pq.push(i);
    }

    vector<int> result;
    while (!pq.empty()) {
        int data = pq.top();
        pq.pop();
        result.push_back(data);
        for (int i = 0; i < arr[data].size(); i++) {
            int b = arr[data][i];
            in_degree[b]--;
            if (in_degree[b] == 0)
                pq.push(b);
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
}