// fast campus 강의
// https://www.acmicpc.net/problem/1759
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
vector<char> alphabet;

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		alphabet.push_back(c);
	}
	sort(alphabet.begin(), alphabet.end());

	vector<bool> pass_chk(C, true);
	fill(pass_chk.end() - L, pass_chk.end(), false);


	vector<string> result;
	do {
		string s = "";
		for (int i = 0; i < C; i++) {
			if (pass_chk[i])
				s += alphabet[i];
		}
		
		int vowels_cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			for (auto v : vowels) {
				if (s[i] == v)
					vowels_cnt++;
			}
		}

		if (vowels_cnt > 0 && s.size() - vowels_cnt > 1)
			result.push_back(s);
	} while (next_permutation(pass_chk.begin(), pass_chk.end()));

	sort(result.begin(), result.end());
	for (auto r : result)
		cout << r << '\n';
}