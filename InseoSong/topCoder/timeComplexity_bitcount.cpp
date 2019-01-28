#include<iostream>

int bitcount(int n) {
	int count = 0;
	int ret = 0;
	while (n > 0) {
		count++;
		if (n % 2 == 1) ret++;
		n /= 2;
	}
	return count;
}

int main() {
	std::cout << bitcount(1000000) << std::endl;
	return 0;
}
