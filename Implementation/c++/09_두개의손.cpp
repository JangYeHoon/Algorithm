// fast campus 강의
// https://www.acmicpc.net/problem/16675
// 1

#include <iostream>

using namespace std;

bool win_chk(char a, char b)
{
	if ((a == 'S' && b == 'P') || (a == 'R' && b == 'S') || (a == 'P' && b == 'R'))
		return true;
	return false;
}

int main()
{
	char ML, MR, TL, TR;
	cin >> ML >> MR >> TL >> TR;

	if (TL == TR && ML != MR) {
		if (win_chk(ML, TL) || win_chk(MR, TL))
			cout << "MS";
		else cout << "?";
	}
	else if (ML == MR && TL != TR) {
		if (win_chk(TL, ML) || win_chk(TR, ML))
			cout << "TK";
		else cout << "?";
	}
	else if (ML == MR && TL == TR) {
		if (win_chk(ML, TL)) cout << "MS";
		else if (win_chk(TL, ML)) cout << "TK";
		else cout << "?";
	}
	else cout << "?";
}