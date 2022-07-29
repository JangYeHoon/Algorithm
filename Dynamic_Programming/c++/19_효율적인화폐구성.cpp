// 이것이 취업을 위한 코딩테스트다
// 2

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int d[10001];

int main() {
	cin >> N >> M;

	memset(d, 10001, sizeof(d));
	d[0] = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		for (int j = x; j <= M; j++) {
			if (d[j - x] != 10001)
				d[j] = min(d[j], d[j - x] + 1);
		}
	}

	if (d[M] == 10001)
		cout << -1;
	else
		cout << d[M];
}
}