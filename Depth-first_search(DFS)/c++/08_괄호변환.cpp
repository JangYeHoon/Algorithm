// 이것이 취업을 위한 위한 코딩테스트다 346p
// https://programmers.co.kr/learn/courses/30/lessons/60058
// 2

#include <string>
#include <vector>

using namespace std;

int balancer(string p)
{
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt == 0)
            return i;
    }
}

bool check(string p)
{
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            cnt++;
        else {
            if (cnt == 0)
                return false;
            cnt--;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if (p == "")
        return answer;
    int idx = balancer(p);
    string u = "", v = "";
    for (int i = 0; i <= idx; i++)
        u += p[i];
    for (int i = idx + 1; i < p.size(); i++)
        v += p[i];

    if (check(u))
        answer = u + solution(v);
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u;
    }
    return answer;
}