#include<stdio.h>
#pragma warning(disable:4996)

const int coverType[4][3][2] = {
	{{0,0}, {1,0},{0,1} },
	{{0,0},{0,1},{1,1} },
	{{0,0},{1,0},{1,1} },
	{{0,0},{1,0},{1,-1} }
};

int cover();
int set(int y, int x, int type, int toggle);
int testcase;
int h=0, w=0;
int board[5][5] = { {0} };

int main(void) {
	
	scanf("%d", &testcase);

	while (testcase) {

		scanf("%d %d", &h, &w);
		
		for (int i = 0; i < h; i++) {
			while (getchar() == '\n')break; //scanf에 값이 제대로 들어가지 않는 경우: 버퍼의 값을 비워 준다

			for (int j = 0; j < w; j++) {
				
				char ch=0;
				scanf("%c", &ch);

				if (ch == '.')
					board[i][j] = 1;
			}	
		}

		printf("%d\n", cover());
		testcase--;
	}

	
	return 0;
}

int set(int y, int x, int type, int toggle) {

	int success = 0;
	int pair1, pair2;

	if (toggle == 1) {
		for (int i = 0; i < 3; i++) {
			pair1 = coverType[type][i][0];
			pair2 = coverType[type][i][1];

			if (board[y + pair1][x + pair2] == 1)
				success = 1;
			else
			{
				success = 0;
				return success;
			}
		}
		for (int i = 0; i < 3; i++) {
			pair1 = coverType[type][i][0];
			pair2 = coverType[type][i][1];
			board[y + pair1][x + pair2] = 0;
		}
	}

	else {
		for (int i = 0; i < 3; i++) {
			pair1 = coverType[type][i][0];
			pair2 = coverType[type][i][1];
			board[y + pair1][x + pair2] = 1;
		}
	}

	return success;
}

int cover() {

	int ret = 0;

	int first = -1, second = -1;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 1)
			{
				first = i;
				second = j;
				break;
			}
		}
	}

	if (first = -1) return 1;

	for (int i = 0; i < 4; i++) {
		
		if (set(first,second,i,1))
		{
			ret += cover();	
		}
		set(first, second, i, -1);
	}
	return ret;
}