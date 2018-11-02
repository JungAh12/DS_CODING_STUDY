#include<stdio.h>
#pragma warning(disable:4996)
#define true 1
#define false 0
#define bool int

int n=0, m=0;
bool areFriends[10][10] = { {false,} };
bool havePair[10] = { false, };

//int countCase(bool* havePair);

int main(void) {

	int testcasecount=0;
	scanf("%d", &testcasecount);

	for (int i = 0; i < testcasecount; i++) {

		for (int k = 0; k < 10; k++) {
			havePair[k] = false;
			for (int j = 0; j < 10; j++) {
				areFriends[k][j] = false;
			}
		}

		scanf("%d %d", &n, &m);

		for (int s = 0; s < m; s++) {
			int a, b;
			scanf("%d %d", &a, &b);
			areFriends[a][b] = areFriends[b][a] = true;
		}
		
		int result = countCase(havePair);
		printf("%d",result);
	}
}

int countCase(bool* havePair) {

	int first = -1;
	for (int i = 0; i < n; i++)
	{
		if (!havePair[i])
		{
			first = i;
			break;
		}
	}

	if (first == -1) return 1;
	int ret = 0;

	for (int i = first + 1; i < n; i++) {
		if (!havePair[i] && areFriends[first][i])
		{
			havePair[first] = havePair[i] = true;
			ret += countCase(havePair);
			havePair[first] = havePair[i] = false;
		}
	}
	return ret;
}