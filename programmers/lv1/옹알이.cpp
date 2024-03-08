// https://school.programmers.co.kr/learn/courses/30/lessons/120956

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string str[4] = { "aya", "ye", "woo", "ma" };
    for (int i = 0; i < babbling.size(); i++) {
        if (babbling[i].find("ayaaya") != string::npos || babbling[i].find("yeye") != string::npos
            || babbling[i].find("woowoo") != string::npos || babbling[i].find("mama") != string::npos)
            continue;

        while (1) {
            int find_chk = 0;
            for (int j = 0; j < 4; j++) {
                if (babbling[i].find(str[j]) != string::npos) {
                    babbling[i].erase(babbling[i].find(str[j]), str[j].size());
                    find_chk = 0;
                }
                else find_chk += 1;
            }
            if (find_chk == 4)
                break;
        }
        if (babbling[i].size() == 0)
            answer += 1;
    }
    return answer;
}