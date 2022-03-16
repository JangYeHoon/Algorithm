// fast campus 강의
// https://www.acmicpc.net/problem/1781
// 0

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp {
    bool operator()(pair<long, long> &a, pair<long, long> &b) {
        return a.second < b.second;
    }
};

int main()
{
    int N;
    priority_queue<pair<long, long>, vector<pair<long, long>>, comp> pq;
    cin >> N;
    for (long i = 0; i < N; i++) {
        long a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    long dead_line = 1, result = 0;
    while (!pq.empty()) {
        result += pq.top().second;
        pq.pop();
        dead_line++;
        while (!pq.empty()) {
            if (pq.top().first < dead_line) {
                pq.pop();
            } else break;
        }
    }
    cout << result;
}