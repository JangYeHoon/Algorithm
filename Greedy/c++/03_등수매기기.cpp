// fast campus 강의
// https://www.acmicpc.net/problem/2012
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> num;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	long result = 0;
	sort(num.begin(), num.end());
	for (int i = 0; i < N; i++) {
		result += abs((i + 1) - num[i]);
	}
	cout << result;
}