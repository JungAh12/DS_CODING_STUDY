
#include "stdafx.h"
#include <stdio.h>
#pragma warning (disable:4996)
int cover(char board[20][20]);
int coverType[4][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,0}},
	{{0,0},{1,-1},{1,0}},
	{{0,0},{0,1},{1,1}}
};
int set(int find[20][20],int fy, int fx, int type, int delta);

int h;
int w;
int main()
{
	int ncase=0;
	int now;
	char board[20][20];

	scanf("%d", &ncase);
	for (int n = 0; n < ncase; n++) {
		now = n;
		h = 0;
		w = 0;
		scanf("%d %d", &h, &w);
		memset(board,' ', sizeof(board));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %c", &board[i][j]);

			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				printf("%c", board[i][j]);

			}printf("\n");
		}//배열 보여줌
		
		
		printf("%d",cover(board));


	}
	return 0;



}
int cover(char board[20][20]) {
	int find[20][20] = { 0, };//1:덮어짐,0:아직
	int fx = -1;
	int fy = -1;
	int result = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == '#'){
				find[i][j] = 1 ;
			//	printf("\n%d0000 %d", i, j);
			}
		}
	}


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d", find[i][j]);

		}printf("\n");
	}


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (find[i][j] == 0) {
				fy = i;
				fx = j;
				break;
			}
		}
		if (fy != -1) break;

	}//첫번째 찾기왼쪽위
	if (fy == -1) return 1;//다 채웠으면 한가지 방법으로 
	for (int type = 0; type < 4; type++) {
		printf("%d", type);
		if (set(find, fy, fx, type, 1)==1){
			result += 1;
			printf("%d", result);
		}
		set(find, fy, fx, type, -1);

	}
	return result;
	 
	 //타입 찾기
	//


}

int set(int find[20][20], int fy, int fx, int type, int delta) {

	int ok = 1;
	for (int i = 0; i < 3; i++) {
		int ny = fy + coverType[type][i][0];
		int nx = fx + coverType[type][i][1];

		if (ny<0 || ny>h || nx < 0 || nx > w) {
			ok = 0;
		}
		else if ((find[ny][nx] += delta) > 1) {
			ok = 0;
		}
		
	}
	return ok;
}
