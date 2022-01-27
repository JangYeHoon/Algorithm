// 럭키 스트레이트
// 입력 : 점수(N), N의 자릿수는 항상 짝수 형태
// 출력 : 럭키 스트레이트를 사용할 수 있으면 "LUCKY", 없으면 "READY"
#include <iostream>
#include <string>

using namespace std;

string str;
int summary = 0;

int main(void) {
	cin >> str;

	// 왼쪽 부분의 자릿수의 합 더하기
	for (int i = 0; i < str.size() / 2; i++) {
		summary += str[i] - '0';
	}

	// 오른쪽 부분의 자릿수의 합 빼기
	for (int i = str.size() / 2; i < str.size(); i++) {
		summary -= str[i] - '0';
	}

	// 왼쪽 부분과 오른쪽 부분의 자릿수 합이 동일한지 검사
	if (summary == 0) cout << "LUCKY" << '\n';
	else cout << "READY" << '\n';
}
