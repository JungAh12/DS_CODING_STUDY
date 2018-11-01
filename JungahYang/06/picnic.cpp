//�� �л����� �ֿ����� �̵��� ���� ģ������ ���ΰ� �־��� ��, �л����� ¦���� �� �ִ� ����� ���� ����ϱ�.

#include <iostream>
using namespace std;

int C; // the number of test Cases
int n; // the number of students	(2<=n<=10)
int m; // friends pairs				(0<=m<=[n(n-1)]/2)


bool friends[10][10];

int countPairs(bool match[10]) {

	//��ȣ ���� ���� �л�
	int first = -1;
	for (int i = 0; i < n; i++) {
		if (!match[i]) {	//¦�� ���� ��ȣ�� ���� ���� �л�
			first = i;
			break;
		}
	}

	//���¦���ִٸ�
	if (first == -1) return true;

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (!match[i] && friends[first][i]) {	//¦�̾��� �л�
			match[first] = match[i] = true;
			result += countPairs(match);
			match[first] = match[i] = false;
		}
	}
	return result;
}
int main() {

	//m���� ���� ������ ���� ģ���� �� �л��� ��ȣ�� �־�����. 0 to n-1 integer.
	//�л� �� ¦��
	
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