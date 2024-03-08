// fast campus 강의
// https://www.acmicpc.net/problem/15969
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> student(N);
    for (int i = 0; i < N; i++)
        cin >> student[i];
    
    int max_value = -1, min_value = 100001;
    for (int i = 0; i< N; i++) {
        max_value = max(max_value, student[i]);
        min_value = min(min_value, student[i]);
    }
    cout << max_value - min_value;
}