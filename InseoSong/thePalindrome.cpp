#include <iostream>
#include <string>

int palindrome(std::string input) {

	int length = input.length();
	static int strLenth = length;
	bool palindrome = false;

	while (!palindrome) {
		for (int i = 0; i < length; i++) {

			int f = i;
			int b = (length - 1) - i;
			
			if (b > (strLenth-1)) {
				continue;
			}

			if (f>=b) {
				palindrome = true;
				return length;

			}
			if (input[f] != input[b]) {
				length++;
				if (length == ((strLenth * 2) - 1)) {
					palindrome = true;
					return length;
				}
				break;
			}
		}
	}
	return length;
}

int main() {
	std::string input;
	std::getline(std::cin, input);
	std::cout << palindrome(input) << std::endl;
	return 0;
}
