// https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> personality;
    char c[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    for (int i = 0; i < 8; i++)
        personality[c[i]] = 0;
    
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4)
            continue;
        else if (choices[i] < 4)
            personality[survey[i][0]] += 4 - choices[i];
        else
            personality[survey[i][1]] += choices[i] - 4;
    }
    
    for (int i = 0; i < 8; i += 2) {
        if (personality[c[i]] >= personality[c[i + 1]])
            answer += c[i];
        else
            answer += c[i + 1];
    }
    return answer;
}