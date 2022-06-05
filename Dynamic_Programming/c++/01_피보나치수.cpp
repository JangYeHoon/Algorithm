// fast campus 강의
// https://www.acmicpc.net/problem/2747
// 1

#include <iostream>

using namespace std;

int n;
long long d[100];

// 반복 풀이
int main(void) {
    cin >> n;

    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; i++)
        d[i] = d[i - 1] + d[i - 2];

    cout << d[n] << '\n';
}

// 재귀
int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}