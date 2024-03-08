// https://school.programmers.co.kr/learn/courses/30/lessons/140107?language=cpp

#include <string>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for (int i = 0; i <= d; i += k) {
        int b = sqrt(pow(d, 2) - pow(i, 2));
        answer += b / k + 1;
    }
    return answer;
}