// 떡볶이 떡 만들기
// 입력 : 떡의 개수(N), 요청한 떡의 길이(M), 떡의 개별 높이
// 출력 : M만큼의 떡을 가져가기 위한 절단기의 높이의 최대값
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &arr, int target, int start, int end)
{
	if (start > end) return -1;
	int mid = (start + end) / 2;
	int result = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int temp = arr[i] - mid;
		if (temp > 0)
			result += temp;
	}
	if (result == target) return mid;
	else if (result > target) return binarySearch(arr, target, mid+1, end);
	else return binarySearch(arr, target, start, mid - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	int result = binarySearch(a, m, 0, a[n - 1]);
	cout << result << '\n';
	return 0;
}