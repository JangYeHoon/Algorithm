// 이것이 취업을 위한 코딩테스트다 197p
// 1

#include <iostream>
#include <vector>

using namespace std;

int N, M;

int binary_search(vector<int> arr, int target, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (arr[mid] == target)
		return arr[mid];
	else if (arr[mid] < target)
		return binary_search(arr, target, mid + 1, end);
	else
		return binary_search(arr, target, start, end - 1);
}

int main() {
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	vector<int> chk(M);
	for (int i = 0; i < M; i++)
		cin >> chk[i];

	for (auto i : chk) {
		if (binary_search(arr, i, 0, N - 1) != -1)
			cout << "yes ";
		else
			cout << "no ";
	}
}