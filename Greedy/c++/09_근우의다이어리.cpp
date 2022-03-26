// fast campus 강의
// https://www.acmicpc.net/problem/16676
// 2

#include <iostream>

using namespace std;

int main()
{
    string N;
    cin >> N;
    if (N.size() == 1) {
        cout << 1;
        return 0;
    }

    string str;
    for (int i = 0; i < N.size(); i++)
        str += '1';
    
    if (str <= N)
        cout << N.size();
    else
        cout << N.size() - 1;
}