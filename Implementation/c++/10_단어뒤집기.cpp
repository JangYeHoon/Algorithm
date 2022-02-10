// https://www.acmicpc.net/problem/9093
// 1

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	int test_case;
	string s;
	cin >> test_case;
	getline(cin, s);

	for (int t = 0; t < test_case; t++) {
		getline(cin, s);
		istringstream ss(s);
		vector<string> sv;
		while (getline(ss, s, ' '))
			sv.push_back(s);

		for (int i = 0; i < sv.size(); i++) {
			reverse(sv[i].begin(), sv[i].end());
			cout << sv[i] << ' ';
		}
		cout << endl;
	}
}