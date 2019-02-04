#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> oz;

vector<vector<int>> fibonacci(int n, vector<vector<int>>&oz) {
	if (oz[n][0] != 0 || oz[n][1] != 0) {
		return oz;
	}
	if (n == 0) {
		oz[n][n]++;
		return oz;
	}
	if (n == 1) {
		oz[n][n]++;
		return oz;
	}
	else {
		fibonacci(n - 1, oz);
		fibonacci(n - 2, oz);
		oz[n][0] += oz[n - 1][0];
		oz[n][1] += oz[n - 1][1];
		oz[n][0] += oz[n - 2][0];
		oz[n][1] += oz[n - 2][1];
		return oz;
	}
}

int main() {
	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		oz.assign(n + 1, vector<int>(2, 0));

		fibonacci(n, oz);
		cout << oz[n][0] << " " << oz[n][1] << endl;
	}
	return 0;
}
