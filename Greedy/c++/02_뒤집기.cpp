// fast campus 강의
// https://www.acmicpc.net/problem/1439
// 1

#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1])
            cnt += 1;
    }
    cout << (cnt + 1) / 2;
}