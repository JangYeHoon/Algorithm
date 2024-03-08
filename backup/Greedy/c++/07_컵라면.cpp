// fast campus 강의
// https://www.acmicpc.net/problem/1781
// 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<pair<int, int>> arr;
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        int deadline = arr[i].first;
        int cup = arr[i].second;
        pq.push(cup);
        result += cup;
        if (pq.size() > deadline) {
            result -= pq.top();
            pq.pop();
        }
    }

    cout << result;
}