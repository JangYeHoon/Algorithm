// fast campus 강의
// https://www.acmicpc.net/problem/1668
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> trophy;

int ascending() {
    int max = trophy[0];
    int result = 1;

    for (int i = 1; i < N; i++) {
        if (trophy[i] > max) {
            max = trophy[i];
            result++;
        }
    }

    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        trophy.push_back(tmp);
    }

    cout << ascending() << '\n';
    reverse(trophy.begin(), trophy.end());
    cout << ascending() << '\n';
}