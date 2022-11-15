// https://school.programmers.co.kr/learn/courses/30/lessons/120821?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    reverse(num_list.begin(), num_list.end());
    return num_list;
}