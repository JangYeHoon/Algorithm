// 모험가 길드
// 입력 : 모험가의 수(N)
//		  각 모험가의 공포도의 값(N이하의 자연수)
// 출력 : 그룹 수의 최댓값
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const int &a, const int &b)
{
	if (a <= b) return false;
	else return true;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), Compare);

	int result = 0;
	int i = 0;
	while (i < n)
	{
		int cnt = v[i];
		if (cnt > n - i)
			break;
		result += 1;
		i += cnt;
	}
	cout << result << '\n';
	return 0;
}