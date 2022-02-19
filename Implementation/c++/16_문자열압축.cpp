// 이것이 취업을 위한 코딩테스트다 325p
// https://programmers.co.kr/learn/courses/30/lessons/60057
// 2

#include <string>

using namespace std;

int solution(string s) {
    int answer = 1e9;
    if (s.size() == 1)
        return 1;

    for (int cnt = 1; cnt < s.size() / 2 + 1; cnt++) {
        string result;
        string tmp = s.substr(0, cnt);
        int str_cnt = 1;
        for (int i = cnt; i < s.size(); i += cnt) {
            if (tmp == s.substr(i, cnt))
                str_cnt++;
            else {
                if (str_cnt == 1)
                    result += tmp;
                else
                    result += to_string(str_cnt) + tmp;
                tmp = s.substr(i, cnt);
                str_cnt = 1;
            }
        }
        if (str_cnt == 1)
            result += tmp;
        else
            result += to_string(str_cnt) + tmp;

        if (answer > result.size())
            answer = result.size();
    }
    return answer;
}