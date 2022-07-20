// fast campus 강의
// https://www.acmicpc.net/problem/11066
// 1

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[501], s[501], d[501][501];

int process(int i, int j) {
    if (i == j)
        return 0;
    if (d[i][j] != -1)
        return d[i][j];
    
    int &ans = d[i][j];
    for (int k = i; k <= j - 1; k++) {
        int tmp = process(i, k) + process(k + 1, j) + s[j] - s[i - 1];
        if (ans == -1 || ans > tmp)
            ans = tmp;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        memset(d, -1, sizeof(d));
        memset(s, 0, sizeof(s));
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        cout << process(1, n) << '\n';
    }
}