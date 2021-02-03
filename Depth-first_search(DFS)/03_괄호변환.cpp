// 괄호 변환
// https://programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>

using namespace std;

int balance(string p)
{
    int count = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            count += 1;
        else
            count -= 1;
        if (count == 0)
            return i;
    }
}

bool check(string p)
{
    int count = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            count += 1;
        else
        {
            if (count == 0)
                return false;
            count -= 1;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";

    if (p == "")
        return answer;
    int a = balance(p);

    string u = "";
    string v = "";
    for (int i = 0; i < a + 1; i++)
        u += p[i];
    for (int i = a + 1; i < p.size(); i++)
        v += p[i];

    if (check(u))
        answer = u + solution(v);
    else
    {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u;
    }

    return answer;
}