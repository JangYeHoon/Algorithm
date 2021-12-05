// fast campus 강의
// https://www.acmicpc.net/problem/1920
// 2

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int N, M, tmp;
	cin >> N;
	set<int> s;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		s.insert(tmp);
	}

	cin >> M;
	int arr[100001] = { 0, };
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}

	for (int i = 0; i < M; i++) {
		if (s.count(arr[i]))
			cout << "1\n";
		else
			cout << "0\n";
	}
}