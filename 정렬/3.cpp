// 두 배열의 원소 교체
// 입력 : 배열의 원소 수(N), 바꿔치기 최대 횟수(K)
//        N개의 원소를 가진 배열 A, B
// 출력 : 배열 A의 모든 원소의 합의 최댓값
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const int &a, const int &b)
{
	if (a <= b) return false;
	return true;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < k; i++)
	{
		if (a[i] > b[i])
			break;
		else
			a[i] = b[i];
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		result += a[i];
	cout << result << '\n';
	return 0;
}