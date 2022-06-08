// fast campus 강의
// https://www.acmicpc.net/problem/1074
// 1

#include <iostream>
#include <cmath>

using namespace std;

int result;
int N, X, Y;

void solve(int n, int x, int y) {
    if (x == X && y == Y) {
        cout << result;
        return;
    }
    else if (n == 1) {
        result++;
        return;
    }
    if (!(x <= X && X < x + n) && !(y <= Y && Y < y + n)) {
        result += pow(n, 2);
        return;
    }
    solve(n / 2, x, y);
    solve(n / 2, x, y + n / 2);
    solve(n / 2, x + n / 2, y);
    solve(n / 2, x + n / 2, y + n / 2);
}

int main() {
    cin >> N >> X >> Y;
    solve(pow(2, N), 0, 0);
}