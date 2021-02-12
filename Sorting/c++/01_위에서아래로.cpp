// 위에서 아래로
// 입력 : 개수(n), 개수만큼의 1이상 100,000이하의 자연수
// 출력 : 내림차순으로 정렬된 결과
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const int &a, const int &b)
{
	if (a < b) return false;
	else return true;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';

	return 0;
}