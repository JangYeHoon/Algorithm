// 이것이 취업을 위한 코딩테스트다 197p
// 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// N(가게의 부품 개수)와 M(손님이 확인 요청한 부품 개수)
int n, m;
// 가게게 있는 전체 부품 번호를 담을 집합(set) 컨테이너
set<int> s;
vector<int> targets;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		targets.push_back(target);
	}
	// 손님이 확인 요청한 부품 번호를 하나씩 확인
	for (int i = 0; i < m; i++) {
		// 해당 부품이 존재하는지 확인
		if (s.find(targets[i]) != s.end()) {
			cout << "yes" << ' ';
		}
		else {
			cout << "no" << ' ';
		}
	}
}