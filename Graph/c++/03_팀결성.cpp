// 팀 결성
// 입력 : 학생 수(N), 연산의 개수(M), M개의 연산
//		  0 a b 팀합치기, a번 학생이 속한 팀과 b번 학생이 속한 팀을 합침
//		  1 a b 같은 팀 여부 확인
// 출력 : 같은 팀 여부 확인 연산에 대한 결과(YES or NO)
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[100001];

int findParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
			unionParent(b, c);
		else if (a == 1)
		{
			if (findParent(b) == findParent(c))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}