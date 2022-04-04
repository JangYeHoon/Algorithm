// 이것이 취업을 위한 코딩테스트다 315p
// 2

#include <iostream>

using namespace std;

int n, m;
int arr[11];

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;
	for (int i = 1; i <= m; i++) {
		n -= arr[i];
		result += arr[i] * n;
	}

	cout << result << '\n';
}