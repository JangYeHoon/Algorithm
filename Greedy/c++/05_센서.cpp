// fast campus 강의
// https://www.acmicpc.net/problem/2212
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, result;
vector<int> lst;
vector<int> distances;

bool comp(int a, int b) {return a > b;}

int main()
{
    cin >> N >> K;
    if (K >= N) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        lst.push_back(temp);
    }
    sort(lst.begin(), lst.end());

    for (int i = 1; i < N; i++) {
        distances.push_back(lst[i] - lst[i - 1]);
        result += lst[i] - lst[i - 1];
    }
    sort(distances.begin(), distances.end(), comp);

    for (int i = 0; i < K - 1; i++)
        result -= distances[i];
    cout << result;
}