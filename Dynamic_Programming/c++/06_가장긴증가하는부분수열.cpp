// fast campus 강의
// https://www.acmicpc.net/problem/11053
// 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int dp[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = 0;
    for (int i = 0; i < N; i++ ) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }

    cout << result;
}