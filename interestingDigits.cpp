#include <iostream>
#include <vector>

inline int convertToBase(int input, int base) {
	int result = 0;
	while (input >= base) {
		result += input / base;
		input -= result * base;
	}
	return result + input;
}

std::vector<int> answer;

void interestingDigits(int base) {

	long long int limit = (base * base * base) - 1;
	for (int i = base - 1; i > 1; i--) {
		int testNum = i * 2;
		bool check = true;
		while (check) {
			if (testNum + i > limit) check = false;
			if (convertToBase(testNum, base) % i != 0 ) break;
			testNum += i;
		}
		if (check == false) answer.push_back(i);
	}

}

int main() {
	int base=0;
	std::cout << "base : ";
	std::cin >> base;
	
	interestingDigits(base);
	
	for (int i = 0; i < answer.size(); i++) {
		std::cout << answer[i] << "  ";
	}
	std::cout << std::endl;

	return 0;
}
