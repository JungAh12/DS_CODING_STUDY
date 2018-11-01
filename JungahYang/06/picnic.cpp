//각 학생들의 쌍에대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지을 수 있는 방법의 수를 계산하기.

#include <iostream>
using namespace std;

int C; // the number of test Cases
int n; // the number of students	(2<=n<=10)
int m; // friends pairs				(0<=m<=[n(n-1)]/2)


bool friends[10][10];

int countPairs(bool match[10]) {

	//번호 가장 빠른 학생
	int first = -1;
	for (int i = 0; i < n; i++) {
		if (!match[i]) {	//짝이 없는 번호가 제일 빠른 학생
			first = i;
			break;
		}
	}

	//모두짝이있다면
	if (first == -1) return true;

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (!match[i] && friends[first][i]) {	//짝이없는 학생
			match[first] = match[i] = true;
			result += countPairs(match);
			match[first] = match[i] = false;
		}
	}
	return result;
}
int main() {

	//m개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어진다. 0 to n-1 integer.
	//학생 수 짝수
	
	cin >> C;
	while (C <= 50) {
	
		cin >> n >> m;
		memset(friends, 0, sizeof(friends));
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			friends[a][b] = friends[b][a] = true;
		}
		bool match[10];
		memset(match, 0, sizeof(match));
		cout << countPairs(match) << endl;
	}
	return 0;

}