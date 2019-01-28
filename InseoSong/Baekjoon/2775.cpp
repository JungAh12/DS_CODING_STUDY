#include <iostream>
using namespace std;

int count(int k, int n) {

	int ans = 0;

	if (k == 0) {
		return n;
	}
	else {
		for (int i = n; i > 0; i--) {
			ans += count(k-1, i);
		}
	}
	return ans;
}

int main() {

	int t = 0, n = 0, k = 0;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k;
		cin >> n;

		cout << count(k, n) << endl;
	}

	return 0;
}
