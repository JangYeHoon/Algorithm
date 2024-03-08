// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/18310
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	cout << arr[(N - 1) / 2];
}