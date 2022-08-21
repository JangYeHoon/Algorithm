// 이것이 취업을 위한 코딩테스트다
// https://school.programmers.co.kr/learn/courses/30/lessons/42889
// 1

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int length = stages.size();
    vector<pair<int, double>> fail_lst;
    for (int i = 1; i <= N; i++) {
        int fail_cnt = count(stages.begin(), stages.end(), i);

        double fail = 0;
        if (length != 0)
            fail = (double)fail_cnt / length;

        fail_lst.push_back({ i, fail });
        length -= fail_cnt;
    }
    sort(fail_lst.begin(), fail_lst.end(), compare);
    for (int i = 0; i < fail_lst.size(); i++)
        answer.push_back(fail_lst[i].first);
    return answer;
}