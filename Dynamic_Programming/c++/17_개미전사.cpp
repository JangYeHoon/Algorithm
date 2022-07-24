// 이것이 취업을 위한 코딩테스트다 220p
// 1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화 
int d[10001];
int n;

int main(void) {
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = a[0];
	d[1] = max(a[0], a[1]);
	for (int i = 2; i < n; i++)
		d[i] = max(d[i - 1], d[i - 2] + a[i]);
	cout << d[n-1] << '\n';
	return 0;
}