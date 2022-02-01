// fast campus 강의
// https://www.acmicpc.net/problem/17269
// 1

#include <iostream>
#include <vector>

using namespace std;

int alpabet[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int N, M;

int main()
{
	cin >> N >> M;
	string A, B;
	cin >> A >> B;

	string full_name;
	int tmp = N <= M ? N : M;
	for (int i = 0; i < tmp; i++) {
		full_name += A[i];
		full_name += B[i];
	}
	if (N > M)
		for (int i = tmp; i < N; i++)
			full_name += A[i];
	else if (M > N)
		for (int i = tmp; i < M; i++)
			full_name += B[i];
	
	vector<int> result;
	for (int i = 0; i < full_name.size(); i++)
		result.push_back(alpabet[full_name[i] - 65]);
	
	for (int i = 0; i < N + M - 2; i++)
		for (int j = 0; j < N + M - i - 1; j++)
			result[j] = (result[j] + result[j + 1]) % 10;

	cout << result[0] * 10 + result[1] << '%';
}