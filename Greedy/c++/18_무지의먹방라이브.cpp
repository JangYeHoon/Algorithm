// 무지의 먹방 라이브
// https://programmers.co.kr/learn/courses/30/lessons/42891
// 2

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long sum_value = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({ -food_times[i], i + 1 });
        sum_value += food_times[i];
    }
    if (sum_value <= k)
        return -1;

    long long previous = 0;
    long long length = food_times.size();
    sum_value = 0;

    while (sum_value + ((-pq.top().first - previous) * length) <= k) {
        int now = -pq.top().first;
        pq.pop();
        sum_value += (now - previous) * length;
        length--;
        previous = now;
    }

    vector<pair<int, int>> answer;
    while (!pq.empty()) {
        int times = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        answer.push_back({ times, idx });
    }
    sort(answer.begin(), answer.end(), compare);
    return answer[(k - sum_value) % length].second;
}