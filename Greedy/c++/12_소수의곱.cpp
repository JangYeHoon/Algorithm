// fast campus 강의
// https://www.acmicpc.net/problem/2014
// 2

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int K, N;
int prime[101];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> prime[i];
        pq.push(prime[i]);
    }

    int index = 0;
    int result = 0;
    while (index < N) {
        result = pq.top();
        pq.pop();
        index++;
        for (int i = 0; i < K; i++) {
            long long temp = 1LL * result * prime[i];
            if (temp < (1LL << 31)) {
                pq.push(temp);
                if (result % prime[i] == 0)
                    break;
            }
        }
    }

    cout << result;
}