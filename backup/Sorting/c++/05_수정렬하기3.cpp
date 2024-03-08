// fast campus 강의
// https://www.acmicpc.net/problem/10989
// 2

#include <iostream>

using namespace std;

int N;
int arr[10001];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp]++;
    }

    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < arr[i]; j++)
            printf("%d\n", i);
    }
}