#include <stdio.h>
#include <malloc.h>
#pragma warning (disable:4996)

// p155

// PICNIC
// �� �л����� �ֿ� ���� �̵��� ���� ģ������ ���ΰ� �־��� �� �л����� ¦���� �� �ִ� ����� �� ����ϱ�
// (�Ϻ� �ָ� �޶� ���� �ٸ� ����̶�� ��)

//input
// ù �ٿ��� �׽�Ʈ ���̽��� �� C(<=50)�� �־���
// �� ���̽��� ù �ٿ��� �л��� �� n(2<=n<=10)�� ģ�� ���� �� m(0<=m<=n(n-1)/2)�� �־���

int c = 1; //�׽�Ʈ ���̽��� ��
int n = 2; //�л���
int m = 0; //ģ������ ��

bool taken[10] = { false };
bool student[10][10] = { false };

int countPairngs(bool taken[10]) {
	int firstFree = -1;

	//������ Ž��
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) { //taken[i]�� false�̸� == ���� ¦�� �������� �ʾ�����
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {

		if (!taken[pairWith] && student[firstFree][pairWith]) {
		
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairngs(taken); //���ȣ��
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {

	int a, b; //ģ���� �ӽ��Է�
	
	scanf("%d", &c);
	int *buffer = (int*)malloc(sizeof(int)*c); //����� ��� ���� ����

	for (int i = 0; i < c; i++) { //�׽�Ʈ ���̽� ����ŭ �ݺ�

		scanf("%d %d", &n, &m); //�л����� ģ���� ���� �Է¹ޱ�

		for (int i = 0; i < m; i++) {

			scanf("%d %d", &a, &b);
			//printf("%d, %d\n", a, b);

			student[a][b] = true;
			student[b][a] = true;
		}

 		buffer[i] = countPairngs(taken);

		if (i == (c - 1)) break;
		//taken�� student false�� �ʱ�ȭ
		for (int i = 0; i < 10; i++) {
			taken[i] = false;
			for (int j = 0; j < 10; j++) {
				student[i][j] = false;
			}
		}

	}

	//����� ���
	for (int i = 0; i < c; i++) {
		printf("%d\n", buffer[i]);
	}

	//��ü ��� ����ϱ�
	//for (int ci = 0; ci < n; ci++) {
	//	for (int ri = 0; ri < n; ri++) {
	//		printf("%d", student[ci][ri]);
	//	}
	//	printf("\n");
	//}

	free(buffer);
	return 0;

}

//int match(bool student[][10]) {
//
//	int numOfCase = 1;
//	int temp = 0;
//	for (int ci = 0; ci < n; ci++) {
//		for (int ri = 0; ri < n-ci; ri++) {
//			if (student[ci][ri]) temp++;
//			//printf("%d", student[ci][ri]);
//		}
//		numOfCase *= temp;
//	}
//	
//	return numOfCase/2;
//}