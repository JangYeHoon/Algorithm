// https://www.acmicpc.net/problem/9093
// 1

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int test_case;
	string s;
	cin >> test_case;
	getline(cin, s);

	for (int t = 0; t < test_case; t++) {
		getline(cin, s);
		istringstream iss(s);
		vector<string> vs;
		while (getline(iss, s, ' ')) {
			reverse(s.begin(), s.end());
			vs.push_back(s);
		}

		for (int i = 0; i < vs.size(); i++)
			cout << vs[i] << ' ';
		cout << '\n';
	}
}