#include <iostream>
#include <string>
using namespace std;

int main() {

	string doorNumber;
	int numbers[9] = { 0 };
	int max = 1;

	cin >> doorNumber;

	for (char n : doorNumber) {
		if (n == '6' || n == '9') numbers[6]++;
		else numbers[(int(n) - 48)]++;
	}

	if (numbers[6] % 2) numbers[6] = (numbers[6] / 2) + 1;
	else numbers[6] /= 2;

	for (int i : numbers) {
		if (i > max) max = i;
	}

	cout << max << endl;

	return 0;
}
