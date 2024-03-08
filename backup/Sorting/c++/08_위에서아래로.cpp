// 이것이 취업을 위한 코딩테스트다 178p
// 2

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const int &a, const int &b)
{
	return a > b
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