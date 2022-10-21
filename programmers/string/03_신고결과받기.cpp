// https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    vector<vector<string>> new_report(report.size());
    for (int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        ss.str(report[i]);
        
        string  word;
        while (ss >> word)
            new_report[i].push_back(word);
    }

    map<string, int> report_cnt;
    for (int i = 0; i < id_list.size(); i++)
        report_cnt[id_list[i]] = 0;
    
    for (int i = 0; i < report.size(); i++)
        report_cnt[new_report[i][1]] += 1;
    
    for (int i = 0; i < report.size(); i++) {
        if (report_cnt[new_report[i][1]] >= k) {
            int idx = find(id_list.begin(), id_list.end(), new_report[i][0]) - id_list.end();
            if (idx >= 0)
                answer[idx] += 1;
        }
    }
    return answer;
}

int main() {
    vector<string> id_list;
    id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report;
    report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    solution(id_list, report, 2);
}