// 곱하기 혹은 더하기
// 입력 : 여러개의 숫자(1~9)로 구성된 문자열 S
// 출력 : 만들 수 있는 가장 큰수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = stoi(s);
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(n % 10);
		n = n / 10;
	}

	int result = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] <= 1 || result <= 1)
			result += v[i];
		else
			result *= v[i];
	}

	cout << result << '\n';
	return 0;
}