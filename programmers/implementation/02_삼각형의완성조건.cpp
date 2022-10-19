// https://school.programmers.co.kr/learn/courses/30/lessons/120868?language=cpp

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int sum = sides[0] + sides[1];
    sort(sides.begin(), sides.end());
    return sum - sides[1] + sides[0] - 1;
}