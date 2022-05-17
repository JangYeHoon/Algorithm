// 이것이 취업을 위한 코딩테스트다 197p
// 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &arr, int target, int start, int end)
{
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
	else return binarySearch(arr, target, mid + 1, end);
}

int main()
{
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = 0; i < m; i++)
	{
		if (binarySearch(a, b[i], 0, n - 1) != -1)
			cout << "yes ";
		else
			cout << "no ";
	}
	return 0;
}