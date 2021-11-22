//
// https://www.acmicpc.net/problem/1874
// 1

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 1;
	int s[100001] = { 0, };
	int top = 0, r = 0;
	char result[400001];
    
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		while (count <= tmp) {
			s[top++] = count;
			result[r++] = '+';
			result[r++] = '\n';
			count += 1;
		}
		
		if (s[--top] == tmp) {
			result[r++] = '-';
			result[r++] = '\n';
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	result[r++] = '\0';

	cout << result;
}