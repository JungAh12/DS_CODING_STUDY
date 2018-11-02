#include <stdio.h>
#include <malloc.h>
#pragma warning (disable:4996)

// p155

// PICNIC
// 각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때 학생들을 짝지을 수 있는 방법의 수 계산하기
// (일부 쌍만 달라도 서로 다른 방법이라고 봄)

//input
// 첫 줄에는 테스트 케이스의 수 C(<=50)가 주어짐
// 각 케이스의 첫 줄에는 학생의 수 n(2<=n<=10)과 친구 쌍의 수 m(0<=m<=n(n-1)/2)가 주어짐

int c = 1; //테스트 케이스의 수
int n = 2; //학생수
int m = 0; //친구쌍의 수

bool taken[10] = { false };
bool student[10][10] = { false };

int countPairngs(bool taken[10]) {
	int firstFree = -1;

	//사전식 탐색
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) { //taken[i]가 false이면 == 아직 짝이 지어지지 않았으면
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {

		if (!taken[pairWith] && student[firstFree][pairWith]) {
		
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairngs(taken); //재귀호출
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {

	int a, b; //친구쌍 임시입력
	
	scanf("%d", &c);
	int *buffer = (int*)malloc(sizeof(int)*c); //결과값 출력 버퍼 생성

	for (int i = 0; i < c; i++) { //테스트 케이스 수만큼 반복

		scanf("%d %d", &n, &m); //학생수와 친구쌍 개수 입력받기

		for (int i = 0; i < m; i++) {

			scanf("%d %d", &a, &b);
			//printf("%d, %d\n", a, b);

			student[a][b] = true;
			student[b][a] = true;
		}

 		buffer[i] = countPairngs(taken);

		if (i == (c - 1)) break;
		//taken과 student false로 초기화
		for (int i = 0; i < 10; i++) {
			taken[i] = false;
			for (int j = 0; j < 10; j++) {
				student[i][j] = false;
			}
		}

	}

	//결과값 출력
	for (int i = 0; i < c; i++) {
		printf("%d\n", buffer[i]);
	}

	//전체 행렬 출력하기
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