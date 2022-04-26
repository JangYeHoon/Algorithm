// fast campus 강의
// https://www.acmicpc.net/problem/1236
// 1

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int row[51], col[51];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    int row_count = 0;
    for (int i = 0; i < N; i++) {
        if (row[i] == 0)
            row_count++;
    }

    int col_count = 0;
    for (int i = 0; i < M; i++) {
        if (col[i] == 0)
            col_count++;
    }

    cout << max(row_count, col_count);
}