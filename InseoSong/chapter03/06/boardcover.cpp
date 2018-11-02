#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <string>
#include <iostream>

#pragma warning (disable:4996)

using std::vector;
using std::string;
using std::cin;
using std::cout;

int c = 0; // �׽�Ʈ ���̽��� ��
int rows = 0;
int cols = 0;

vector< vector<int> > board;

// {dy, dx}
// ��ġ�� ���� ����� ��ġ
const int coverType[4][3][2] = {
	{ { 0, 0 },{ 1, 0 },{ 0, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 1, -1 } }
};

bool set(vector< vector<int> >& board, int y, int x, int type, int delta){
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) ok = false;
	}
	return ok;
}

int cover(vector< vector<int> >& board) {

	int y = -1, x = -1;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		
		if (y != -1) break;
	}

	if (y == -1) return 1;
	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1)) ret += cover(board);
		set(board, y, x, type, -1);
		}

	return ret;
	
}

int main() {

	string tmp; // line���� �Է�

	scanf("%d", &c);
	int *buffer = (int*)malloc(sizeof(int)*c); //����� ��� ����

	for (int i = 0; i < c; i++) {
		scanf("%d %d", &rows, &cols);
		
		for (int y = 0; y < rows; y++) {
			board.push_back(vector<int>(0, 0));
			cin >> tmp;
			for (int x = 0; x < cols; x++) {
				if (tmp[x]=='#') board[y].push_back(1); // # �̸� 1 ����
				else board[y].push_back(0); // *�̸� 0 ����
			}
		}

		buffer[i] = cover(board);

		if (i == (c - 1)) break;
		else board.clear();
	}

	// board ��ü���
	//for (int y = 0; y < rows; y++) {
	//	for (int x = 0; x < cols; x++) {
	//		cout << board[y][x];
	//	}
	//	cout << std::endl;
	//}

	for (int i = 0; i < c; i++) {
		printf("%d\n", buffer[i]);
	}

	return 0;
}