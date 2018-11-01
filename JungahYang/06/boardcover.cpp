#include <vector>
#include <iostream>

using namespace std;

int c;
int H, W;
const int coverBlock[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

//��ġ�ų�, ���� ĭ�� ������ false, ����� �������� ����� false
bool set(int** board, int y, int x, int type, int delta) {

	bool done = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverBlock[type][i][0];
		const int nx = x + coverBlock[type][i][1];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			done = false;

		else if ((board[ny][nx] += delta) > 1)
			done = false;
	}
	return done;
}

int cover(int ** board, int H, int W) {

	int y = -1, x = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == 0)	//������ �ʾҴٸ�
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)break;
	}
	//��� ĭ ä��� 1��ȯ
	if (y == -1) return 1;

	int rs = 0;
	for (int type = 0; type < 4; ++type) {
		//type�� �ٲ㰡�鼭 ���� �� �ִ��� Ȯ��
		if (set(board, y, x, type, 1))
			rs += cover(board,H,W);
		//���� ��� �����.
		set(board, y, x, type, -1);
	}
	return rs;
}

int main() {

	cin >> c;
	
	
	int i = 0;

	while (i < c) {
		cin >> H >> W;
		if (H <= 1 || W >= 20) {
			exit(1);
		}
		int** board = new int*[H];
		char match[20];
		int white = 0;

		for (int i = 0; i < H; ++i) {
		
			cin >> match;
			board[i] = new int[W];
			for (int j = 0; j < W; ++j) {
		
				board[i][j] = (match[j] == '#') ? 1 : 0;
				if (board[i][j] == 0)
					++white;

			}
		}
		cout << cover(board,H,W) << endl;
	}
}