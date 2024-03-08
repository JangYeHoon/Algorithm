// fast campus 강의
// https://www.acmicpc.net/problem/2920
// 2

#include <iostream>

using namespace std;

int main()
{
	int n[8] = { 0, };
	for (int i = 0; i < 8; i++)
		cin >> n[i];

	bool ascending = true, descending = true;
	for (int i = 1; i < 8; i++) {
		if (n[i] < n[i - 1])
			ascending = false;
		else if (n[i] > n[i - 1])
			descending = false;
	}

	if (ascending)
		cout << "ascending" << endl;
	else if (descending)
		cout << "descending" << endl;
	else cout << "mixed" << endl;
}