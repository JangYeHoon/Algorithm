// fast campus 강의
// https://www.acmicpc.net/problem/16165
// 1

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	map<string, string> map_groups;		// key:member, value:group
	map<string, set<string>> map_members;	// key:group, value:members

	for (int i = 0; i < N; i++) {
		string group;
		int cnt;
		cin >> group >> cnt;

		for (int j = 0; j < cnt; j++) {
			string member;
			cin >> member;
			map_members[group].insert(member);
			map_groups[member] = group;
		}
	}

	for (int i = 0; i < M; i++) {
		int cnt;
		string q;
		cin >> q >> cnt;

		if (cnt == 0) {
			for (auto m : map_members[q])
				cout << m << '\n';
		}
		else cout << map_groups[q] << '\n';
	}
}