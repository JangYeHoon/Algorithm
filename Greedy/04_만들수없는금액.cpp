// 만들 수 없는 금액
// 입력 : 동전의 개수(N)
//		  동전의 화폐 단위
// 출력 : 동전으로 만들 수 없는 금액 중 최소값
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int target = 1;
	if (target == v[0])
		target += v[0];
	for (int i = 1; i < n; i++)
	{
		if (target >= v[i])
			target += v[i];
		else
			break;
	}

	cout << target << '\n';
	return 0;
}