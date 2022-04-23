// fast campus 강의
// https://www.acmicpc.net/problem/1568
// 2

#include <iostream>

using namespace std;

int N, idx = 1, result;

int main()
{
    cin >> N;

    while (N > 0) {
        if (idx > N)
            idx = 1;
        N -= idx;
        idx++;
        result++;
    }
    cout << result;
} 