// 성적이 낮은 순서로 학생 출력하기
// 입력 : 학생수(n), n명의 학생이름과 점수
// 출력 : 성적이 낮은 순서대로 학생이름 출력
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
	if (a.second > b.second) return false;
	else return true;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<string, int>> v;

	for (int i = 0; i < n; i++)
	{
		int a;
		string s;
		cin >> s >> a;
		pair<string, int> p = make_pair(s, a);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
		cout << v[i].first << ' ';

	return 0;
}