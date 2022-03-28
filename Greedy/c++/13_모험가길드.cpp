// 이것이 취업을 위한 코딩테스트다 311p
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int result = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		count++;
		if (count >= v[i]) {
			result++;
			count = 0;
		}
	}

	cout << result;
}