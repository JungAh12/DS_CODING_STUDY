#include <iostream>
#include <vector>
#include <algorithm>
#define WIDTH 28
#define HEIGHT 28
#define START 14
using namespace std;

class CrazyBot {
	bool gridWorld[WIDTH][HEIGHT] = { false };
	int x[4] = { 1,-1,0,0 };
	int y[4] = { 0,0,-1,1 };
	double result = 0;

public: double getProbability(int n, int east, int west, int south, int north) {
	double prob[4];
	prob[0] = east/100.0;
	prob[1] = west/100.0;
	prob[2] = south/100.0;
	prob[3] = north/100.0;
	return movingCheck(START, START,n, prob);
}

public: double movingCheck(int a, int b, int n, double * prob) {
	
	
	if (gridWorld[a][b]) //이미 지나갔던 곳이면 0 반환
		return 0;
	if (n == 0)			//다 움직였으면 1 반환
		return 1;
	
	gridWorld[a][b] = true;
	cout <<"a"<< a <<"b"<< b <<"visited"<< gridWorld[a][b] << endl;
	double result = 0.0;
	for (int i = 0; i < 4; i++) { //동서남북 움직임

		result += movingCheck(a+x[i], b+y[i],n-1,prob)*prob[i];
		cout << "result " << result<<endl;
	}
	gridWorld[a][b] = false;  //다음의 움직임을 위해서 false로 바꿔준다.
	return result;
}
};

int main() {

	CrazyBot cb = CrazyBot();
	int n, east, west, south, north;
	cin >> n;
	cin >> east;
	cin >> west;
	cin >> south;
	cin >> north;

	cout<<cb.getProbability(n, east, west, south, north);
	return 0;
}
