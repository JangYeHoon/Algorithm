// https://school.programmers.co.kr/learn/courses/30/lessons/131127?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> want_dict;
    for (int i = 0; i < want.size(); i++)
        want_dict.insert({want[i], number[i]});
    
    for (int i = 0; i < discount.size() - 9; i++) {
        map<string, int> discount_dict;
        for (int j = i; j < i + 10; j++) {
            if (discount_dict.find(discount[j]) == discount_dict.end())
                discount_dict.insert({discount[j], 1});
            else
                discount_dict[discount[j]] += 1;
        }
        
        bool chk = true;
        for (auto k : want_dict) {
            if (discount_dict.find(k.first) == discount_dict.end() || k.second != discount_dict[k.first])
                chk = false;
        }
        if (chk)
            answer++;
    }
    return answer;
}