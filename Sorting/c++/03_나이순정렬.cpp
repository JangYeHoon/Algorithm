// fast campus 강의
// https://www.acmicpc.net/problem/10814
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, string>> members;
	for (int i = 0; i < N; i++) {
		int temp;
		string s;
		cin >> temp >> s;
		members.push_back({ temp, s });
	}
	stable_sort(members.begin(), members.end(), compare);

	for (int i = 0; i < N; i++)
		cout << members[i].first << " " << members[i].second << '\n';
}