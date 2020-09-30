// 성적이 낮은 순서로 학생 출력하기
// 입력 : 학생수(n), n명의 학생이름과 점수
// 출력 : 성적이 낮은 순서대로 학생이름 출력
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수가 낮은 순서'
	bool operator <(Student &other) {
		return this->score < other.score;
	}
};

int n;
vector<Student> v;

int main(void) {
	// N을 입력받기
	cin >> n;

	// N명의 학생 정보를 입력받아 리스트에 저장
	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());

	// 정렬이 수행된 결과를 출력
	for (int i = 0; i < n; i++) {
		cout << v[i].name << ' ';
	}
}