// fast campus 강의
// https://www.acmicpc.net/problem/2437
// 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	int result = 0;
	for (auto a : arr) {
		if (a <= result + 1)
			result += a;
		else
			break;
	}
	cout << result + 1;
}