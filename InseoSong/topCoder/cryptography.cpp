#include <algorithm>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

long long int crypto(vector<int> &input) {

	sort(input.begin(), input.end());
	input[0]++;

	long long int result = 1;
	for (int i : input) {
		result *= i;
	}
	return result;
}

int main() {

	//cout << "input numbers" << endl;
	std::vector<int> input1 = { 1, 2, 3 };
	std::vector<int> input2 = { 1, 3, 2,1,1,3 };
	std::vector<int> input3 = { 1000,999,998,997,996,995 };

	cout << "input1 returns: " << crypto(input1) << endl;
	cout << "input2 returns: " << crypto(input2) << endl;
	cout << "input3 returns: " << crypto(input3) << endl;

	return 0;
}
