// fast campus 강의
// https://www.acmicpc.net/problem/1300
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> A;

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    sort(A.begin(), A.end());

    cout << A[K - 1];
}