// fast campus 강의
// https://www.acmicpc.net/problem/10539
// 2

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> B(N);
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> B[i];

	A[0] = B[0];
	int memorization = A[0];
	for (int i = 1; i < N; i++) {
		int tmp = B[i] * (i + 1);
		A[i] = tmp - memorization;
		memorization += A[i];
	}

	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';
}