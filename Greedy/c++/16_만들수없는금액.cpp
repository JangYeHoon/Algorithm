// 이것이 취업을 위한 코딩테스트다 314p
// 비슷한 문제 : https://www.acmicpc.net/problem/2437
// 1

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
	for (int i = 0; i < n; i++)
	{
		if (target < v[i])
			break;
		target += v[i];
	}

	cout << target << '\n';
}