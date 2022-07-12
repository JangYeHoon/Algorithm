// fast campus 강의
// https://www.acmicpc.net/problem/12849
// 0

#include <iostream>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll arr[8] = { 1 }, tarr[8];
int D;

void doit() {
    tarr[0] = arr[1] + arr[2];
    tarr[1] = arr[0] + arr[2] + arr[3];
    tarr[2] = arr[0] + arr[1] + arr[3] + arr[4];
    tarr[3] = arr[1] + arr[2] + arr[4] + arr[5];
    tarr[4] = arr[2] + arr[3] + arr[5] + arr[6];
    tarr[5] = arr[3] + arr[4] + arr[7];
    tarr[6] = arr[4] + arr[7];
    tarr[7] = arr[5] + arr[6];
    for (int i = 0; i < 8; i++) {
        arr[i] = tarr[i] % MOD;
    }
}

int main() {
    cin >> D;
    for (int i = 0; i < D; i++)
        doit();
    cout << arr[0];
}