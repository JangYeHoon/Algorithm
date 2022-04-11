// fast campus 강의
// https://www.acmicpc.net/problem/11650
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> p;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < N; i++)
        cout << p[i].first << " " << p[i].second << '\n';
}