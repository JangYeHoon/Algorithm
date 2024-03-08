// 이것이 취업을 위한 코딩테스트다
// https://www.acmicpc.net/problem/10825
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int kor;
	int eng;
	int math;

	Student(string name, int kor, int eng, int math) {
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->math = math;
	}

	bool operator <(Student& other) {
		if (this->kor == other.kor && this->eng == other.eng && this->math == other.math) {
			return this->name < other.name;
		}
		if (this->kor == other.kor && this->eng == other.eng) {
			return this->math > other.math;
		}
		if (this->kor == other.kor) {
			return this->eng < other.eng;
		}
		return this->kor > other.kor;
	}
};

int N;
vector<Student> students;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		students.push_back(Student(name, kor, eng, math));
	}

	sort(students.begin(), students.end());

	for (auto student : students)
		cout << student.name << '\n';
}