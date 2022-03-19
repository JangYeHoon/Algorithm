// fast campus 강의
// https://www.acmicpc.net/problem/1461
// 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, result;
vector<int> arr;
priority_queue<int> positive, negative;
int max_value = -10001;
int min_value = 10001;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        max_value = max(max_value, tmp);
        min_value = min(min_value, tmp);
    }

    int largest = max(max_value, -min_value);

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0)
            positive.push(arr[i]);
        else
            negative.push(-arr[i]);
    }

    while (!positive.empty()) {
        result += positive.top();
        positive.pop();
        for (int i = 0; i < M - 1; i++) {
            if (!positive.empty())
                positive.pop();
        }
    }

    while (!negative.empty()) {
        result += negative.top();
        negative.pop();
        for (int i = 0; i < M - 1; i++) {
            if (!negative.empty())
                negative.pop();
        }
    }

    cout << result * 2 - largest;
}