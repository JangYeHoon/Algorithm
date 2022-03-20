// fast campus 강의
// https://www.acmicpc.net/problem/17224
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, L, K;
    int easy = 0;
    int difficult = 0;
    cin >> N >> L >> K;
    
    for (int i = 0; i < N; i++) {
        int sub1, sub2;
        cin >> sub1 >> sub2;
        if (sub2 <= L)
            difficult += 1;
        else if (sub1 <= L)
            easy += 1;
    }

    int result = min(difficult, K) * 140;
    if (difficult < K)
        result += min(K - difficult, easy) * 100;
    cout << result;
}