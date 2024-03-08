// 이것이 취업을 위한 코딩테스트다 335p
// https://programmers.co.kr/learn/courses/30/lessons/60062
// 2

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    int weak_length = weak.size();
    for (int i = 0; i < weak_length; i++)
        weak.push_back(weak[i] + n);
    int dist_count = 1;
    for (int i = 0; i < weak_length; i++) {
		do {
			int count = 1;
			int position = weak[i] + dist[count - 1];
			for (int j = i; j < i + weak_length; j++) {
				if (position < weak[j]) {
					count += 1;
					if (count > dist.size())
						break;
					position = weak[j] + dist[count - 1];
				}
			}
			answer = min(answer, count);
		} while (next_permutation(dist.begin(), dist.end()));
    }
    if (answer > dist.size())
        return -1;
    return answer;
}