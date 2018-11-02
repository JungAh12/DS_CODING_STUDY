#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>

#define _DEBUG false
using namespace std;

//const bool  = false;

const int INF = numeric_limits<int>::max(); //2147483647

const int CLOCK_CNT = 16;
const int SWITCH_CNT = 10;

const vector<vector<int> > switches({
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
	});

/*
const vector< vector<bool> > switches (10, vector<bool>(0, false));
*/

vector<int> clocks({ 12,9,3,12,6,6,9,3,12,9,12,9,12,12,6,6 });
//vector<int> clocks;

void clickSwitch(int switch_no) {
	for (const int &c : switches[switch_no]) // 범위기반 for문
		clocks[c] = (clocks[c] + 1) % 4;
}

bool areClockAligned() {
	for (const int &c : clocks) {
		if (c != 0)
			return false;
	}

	return true;
}

int getClickCnt(int switch_no) {
	if (_DEBUG) {
		for (int i = 0; i < switch_no; ++i) {
			cout << "  ";
		}
		cout << "Swtich " << switch_no << endl;
	}

	if (areClockAligned()) {
		return 0;
	}

	if (switch_no >= SWITCH_CNT)
		return INF;

	int ret = INF;

	for (int i = 0; i < 4; i++) {
		if (_DEBUG) {
			for (int i = 0; i < switch_no; ++i) {
				cout << "  ";
			}
			cout << "  " << i << " click" << endl;
		}

		int sub_ret = getClickCnt(switch_no + 1);

		if (_DEBUG) {
			for (int i = 0; i < switch_no; ++i) {
				cout << "  ";
			}
			cout << "Result: " << sub_ret << endl;
		}

		clickSwitch(switch_no);
		if (sub_ret == INF)
			continue;
		ret = min(ret, i + sub_ret);
	}

	return ret;
}

string getClocks() {
	string ret;
	for (const int &x : clocks) {
		ret += to_string(x) + " ";
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	int T = 1; //케이스의 수
	//cin >> T;

	for (int t = 0; t < T; t++) {
		clocks.clear(); //테스트 케이스마다 vector clocks를 비움

		//for (int i = 0; i < CLOCK_CNT; i++) {
		//	int clock;
		//	cin >> clock;
		//	clocks.push_back((clock / 3) % 4); // 3->1, 6->2, 12->0
		//}

		int Answer = getClickCnt(0);
		Answer = ((Answer == INF) ? -1 : Answer); // 답이 INF(답이 없음)이면 -1 출력

		cout << Answer << '\n';
	}

	return 0;
}

// https://github.com/PeppyDays/Algorithm-Solving/blob/master/Algospot/CLOCKSYNC.cpp