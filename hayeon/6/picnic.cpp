//

#include "stdafx.h"
#include <stdio.h>
#pragma warning (disable:4996)
int findd(int nom[10]);
int n;//사람
int m;//친구 쌍
int now;
int ncase = 0;
int friends[10][10] = { 0, };


int main()
{
	int nom[10] = { 0, };//출력
	int f[90] = { 0, };

	scanf("%d", &ncase);
	for (int i = 0; i < ncase; i++) {
		now = i;
		n = 0;
		m = 0;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m * 2; j++) {
			scanf(" %d", &f[j]);
			if (j % 2 == 1) {

				friends[f[j]][f[j - 1]] = 1;
				friends[f[j-1]][f[j ]] = 1;
			}


		}//친구사이 까지 입력
		/*
		for (int k = 0; k < n; k++) {
			for (int u = 0; u < n; u++) {
				printf("%d ", friends[k][u]);
			}
			printf("\n");
		}
		*/
		printf("%d",findd(nom));
		//재귀함수 넣어야함
	}
}

int findd(int nom[10]) {

	int first=-1;
	//첫번째 사람 찾고, 모두 팀을 이루면 나와야함

	for(int i = 0; i < n; i++) {

		if (nom[i] == 0) {
			first = i;
			break;
		}
	}
	if (first == -1) return 1;
	int result = 0;
	for (int j = first+ 1; j < n; j++) {
		if (friends[first][j] == 1 && nom[j] == 0) {//서로 친구고, 아직 친구 안찾았을때 이어줌
			nom[j] = 1;
			nom[first] = 1;
			result += findd(nom);
			nom[first] = 0;
			nom[j] = 0;
		}
		
	}
	return result;
}
