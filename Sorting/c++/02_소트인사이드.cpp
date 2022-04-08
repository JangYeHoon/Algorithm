// fast campus 강의
// https://www.acmicpc.net/problem/1427
// 1

#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	for (int i = 9; i >= 0; i--) {
        for (char x: s) {
            if (x - '0' == i)
                cout << i;
        }
    }
}