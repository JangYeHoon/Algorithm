// fast campus 강의
// https://www.acmicpc.net/problem/12865
// 0

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int d[101][100001];

int main () {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = 1;j <= K; j++) {
            if (j < w)
                d[i][j] = d[i - 1][j];
            else
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w] + v);
        }
    }
    cout << d[N][K];
}