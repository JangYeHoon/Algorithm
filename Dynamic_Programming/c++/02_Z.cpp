// fast campus 강의
// https://www.acmicpc.net/problem/1074
// 2

#include <iostream>
#include <cmath>

using namespace std;

int N, result, r, c;

void Z(int x, int y, int n) {
	if (x == r && y == c) {
		cout << result;
		return;
	}
	else if (n == 1) {
		result++;
		return;
	}
	if (!(x <= r && r < x + n) && !(y <= c && c < y + n)) {
		result += pow(n, 2);
		return;
	}
	Z(x, y, n / 2);
	Z(x, y + n / 2, n / 2);
	Z(x + n / 2, y, n / 2);
	Z(x + n / 2, y + n / 2, n / 2);
}

int main() {
	cin >> N >> r >> c;
	Z(0, 0, pow(2, N));
}