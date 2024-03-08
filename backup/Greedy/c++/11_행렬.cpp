// fast campus 강의
// https://www.acmicpc.net/source/35089622
// 2

#include <iostream>

int N, M;
int A[51][51];
int B[51][51];

void flip(int x, int y) {
	for (int i = x; i <= x + 2; i++) {
		for (int j = y; j <= y + 2; j++)
			A[i][j] = 1 - A[i][j];
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &A[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &B[i][j]);

	int result = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				result++;
				flip(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", result);
}