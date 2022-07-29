// 이것이 취업을 위한 코딩테스트다 220p
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
int d[1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);
	for (int i = 2; i < N; i++)
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);

	cout << *max_element(d, d + N);
}