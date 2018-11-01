#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int>& picked, int toPick) {

	for (int i = 0; i < picked.size(); i++) {
		cout << picked[i];
	}
}

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked, toPick);
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}
/*
int main() {

	vector<int> list;
	
	pick(5, list, 2);
}
*/