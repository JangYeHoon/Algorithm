// https://school.programmers.co.kr/learn/courses/30/lessons/138476?language=cpp

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tangerine_map;
	for (int i = 0; i < tangerine.size(); i++)
		tangerine_map[tangerine[i]] += 1;
	
	vector<pair<int, int>> tangerine_sort(tangerine_map.begin(), tangerine_map.end());
	sort(tangerine_sort.begin(), tangerine_sort.end(), comp);
	
	for (int i = 0; i < tangerine_sort.size(); i++) {
		answer++;
		k -= tangerine_sort[i].second;
		if (k <= 0)
			break;
	}
    return answer;
}