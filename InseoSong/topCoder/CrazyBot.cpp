#include <iostream>
using std::cin;
using std::cout;

//enum direction {east, west, south, north};
#define START 13
#define GRID_SIZE 28

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class CrazyBot {
public:
	static int n;
	static double prob[4];
	static double answer;

	bool visited[GRID_SIZE][GRID_SIZE] = { false };
	
	CrazyBot(){
		cin >> n;
		cin >> prob[0];
		cin >> prob[1];
		cin >> prob[2];
		cin >> prob[3];

		for (int i = 0; i < 4; i++) {
			prob[i] /= 100;
		}

		answer = 0;
		move(0, START, START, visited);
	}
	static double move(int cur, int x, int y, bool visited[][GRID_SIZE]) {
		
		double p = 1;
		
		if (!visited[x][y]) {
			if (cur == n) {
				answer += p;
				return 1;
			}
			visited[x][y] = true;

			for (int i = 0; i < 4; i++) {
				p *= prob[i]*move(cur + 1, x + dx[i], y + dy[i], visited);
			}
		}

		else return 0;

		return p;
		
	}

};

int main() {

	CrazyBot* bot = new CrazyBot;
	cout << bot->answer << std::endl;

	return 0;
}
