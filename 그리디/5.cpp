// 볼링공 고르기
// 입력 : 볼링공의 개수(N), 공의 최대 무게(M)
//		  볼링공의 무게(K)가 순서대로
// 출력 : 두 사람이 볼링공을 고르는 경우의 수
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> k(n);
	for (int i = 0; i < n; i++)
		cin >> k[i];

	int result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (k[i] == k[j])
				continue;
			result += 1;
		}
	}

	cout << result << '\n';
	return 0;
}