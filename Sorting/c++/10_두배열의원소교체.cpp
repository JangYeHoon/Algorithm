// 이것이 취업을 위한 코딩테스트다 182p
// 1

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