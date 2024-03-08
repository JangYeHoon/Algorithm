// fast campuse 강의
// https://www.acmicpc.net/problem/5585
// 2

#include <iostream>

using namespace std;

int main()
{
    int change, result = 0;
    int money[6] = {500, 100, 50, 10, 5, 1};
    cin >> change;
    change = 1000 - change;
    for (int i = 0; i < 6; i++) {
        result += change / money[i];
        change %= money[i];
    }
    cout << result;
}