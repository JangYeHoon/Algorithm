// fast campus 강의
// https://www.acmicpc.net/problem/2014
// 0

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

    int prev = -1;
    for (int i = 0; i < N-1 ; i++) {
        int curr = PQ.top();
        PQ.pop();
        for (int j = 0 ; j < K ; j++) {
            long long temp = 1LL * curr * P[j];

            if(temp < (1LL<<31))
                PQ.push(temp);
            else
                break;
        }
        prev = curr;
        while(prev == PQ.top())
            PQ.pop();
    }
    cout << PQ.top();
}