// fast campus 강의
// https://www.acmicpc.net/problem/2751
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';
}