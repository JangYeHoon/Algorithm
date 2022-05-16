// fast campus 강의
// https://www.acmicpc.net/problem/17406
// 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N, M, K, result = 1e9;
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, -1, 0, 1 };

int arr_min(vector<vector<int>> A) {
    int ret = 1e9;
    for (auto i : A) {
        int tmp = 0;
        for (auto j : i)
            tmp += j;
        ret = min(ret, tmp);
    }
    return ret;
}

vector<vector<int>> rotate(vector<vector<int>> A, vector<int> Q) {
    int r = Q[0];
    int c = Q[1];
    int s = Q[2];
    r--; c--;
    vector<vector<int>> ret = A;
    for (int d = 1; d <= s; d++) {
        int px = r - d;
        int py = c + d;
        for (int i = 0; i < 4; i++) {
            for (int dd = 0; dd < 2 * d; dd++) {
                ret[px + mx[i]][py + my[i]] = A[px][py];
                px += mx[i];
                py += my[i];
            }
        }
    }
    return ret;
}

void dfs(vector<vector<int>> A, vector<vector<int>> Q, vector<int> chk) {
    if (accumulate(chk.begin(), chk.end(), 0) == K) {
        result = min(result, arr_min(A));
        return;
    }

    for (int i = 0; i < K; i++) {
        if (chk[i])
            continue;
        vector<vector<int>> rotate_A = rotate(A, Q[i]);
        chk[i] = 1;
        dfs(rotate_A, Q, chk);
        chk[i] = 0;
    }
}

int main() {
    cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> Q(K, vector<int>(3));
    vector<int> chk(K, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 3; j++)
            cin >> Q[i][j];
    }
    dfs(A, Q, chk);
    cout << result;
}