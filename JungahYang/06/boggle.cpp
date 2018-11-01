#include <iostream>
using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
string dictionary[3] = { "pretty", "girl","repeat" };
char board[5][5] = { {'u','r','l','p','m'},
					 {'x','p','r','e','t'},
					 {'g','i','a','e','t'},
					 {'x','t','n','z','y'},
					 {'x','o','q','r','s'} };

bool inRange(int x, int y) {
	
	if (x > 4 || y > 4) return false;
	return true;
}
bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;

	if (word.size() == 1) { 
		return true; }

	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		
		if (hasWord(nextY, nextX, word.substr(1))) {
			return true;
		}
	}
	return false;
}
/*
int main() {

	hasWord(1, 1, dictionary[0]);
	
	return 0;
}
*/