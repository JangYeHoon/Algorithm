// 이것이 취업을 위한 코딩테스트다
// 1

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int binary_search(vector<int> arr, int start, int end) {
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	if (mid == arr[mid])
		return mid;
	else if (arr[mid] >= mid)
		return binary_search(arr, start, mid - 1);
	else
		return binary_search(arr, mid + 1, end);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	cout << binary_search(arr, 0, N - 1);
}