// https://school.programmers.co.kr/learn/courses/30/lessons/133502?language=cpp

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int hambuger[4] = { 1, 2, 3, 1 };
    vector<int> s;
    for (int i = 0; i < ingredient.size(); i++) {
        s.push_back(ingredient[i]);
        if (s.size() >= 4) {
            bool chk = true;
            for (int j = s.size() - 4; j < s.size(); j++) {
                if (s[j] != hambuger[j - (s.size() - 4)])
                    chk = false;
            }

            if (chk) {
                answer++;
                for (int j = 0; j < 4; j++)
                    s.pop_back();
            }
        }
    }
    return answer;
}