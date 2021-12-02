// fast campus 강의
// https://www.acmicpc.net/problem/1920
// 1

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int N, M, tmp;
	set<int> A;
	vector<int> search;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		search.push_back(tmp);
	}

	for (auto s : search) {
		if (A.count(s))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}