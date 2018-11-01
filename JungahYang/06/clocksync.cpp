#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define SWITCH 10
#define CLOCKS 16

using namespace std;

const char linklist[SWITCH][CLOCKS+1] = {
"000.............",
"...0...0.0.0....",
"....0.....0...00",
"0...0000........",
"......000.0.0...",
"0.0...........00",
"...0..........00",
"....00.0......00",
".00000..........",
"...000...0...0.."
};
bool check_12(const vector<int>& clocks) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (clocks[clock] != 12)
			return false;
	}
	return true;
}

void push(vector<int>& clocks, int swt) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linklist[swt][clock] == '0') {
			clocks[clock] += 3;
			if (clocks[clock] == 15)
				clocks[clock] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swt) {

	if (swt == SWITCH)
		return check_12(clocks) ? 0 : 99999;

	int rs = 99999;
	for (int cnt = 0; cnt < 4; ++cnt) {
		rs = min(rs, cnt + solve(clocks, swt + 1));
		push(clocks, swt);
	}

	return rs;
}

int main() {

	
	int c;
	cin >> c;
	int j = 0;

	while (j < c) {
		vector<int> clocks;
		int time;
		for (int i = 0; i < CLOCKS; ++i) {

			cin >> time;
			clocks.push_back(time);

			if (!(time == 3 || time == 6 || time == 9 || time == 12)) {
				cout << "시간 값 오류";
				exit(1);
			}
		}

		cout << solve(clocks, 0);
	}
}