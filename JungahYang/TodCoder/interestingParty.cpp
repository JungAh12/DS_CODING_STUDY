#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int people = 0;

int happyParty(string * first, string * second) {
	int friendNum = 0;
	for (int i = 0; i < people; ++i) {
		int localnum = 0;
		for (int j = 0; j < people; ++j) {
			if (i == j) continue;
			if (first[i] == second[j] || first[i] == first[j] || second[i] == second[j]) {
				cout << "frist" << i << " second" << j << endl;
				++localnum;
			}
		}
		friendNum = max(friendNum, localnum)+1;
		cout << friendNum<<endl;
	}
	return friendNum;
}
void main() {
	
	cout << "사람 수 입력 : ";
	cin >> people;

	string * first = new string[people];
	string * second = new string[people];

	for (int i = 0; i < people; ++i) {
		string hobby;
		cout << i << "번째 사람의 취미 입력(엔터로 구분)"<<endl;
		cin >> first[i];
		cin >> second[i];
	}

	cout << happyParty(first, second)<<"명"<<endl;

}
