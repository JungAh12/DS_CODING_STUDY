#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class InterestingDigits {
public: vector <int> digits(int base) {
	vector <int> answer;
	for (int n = 2; n < base; n++) {
		bool ok = true;

		//k1,k2,k3는 각각의 자릿수 4자리수 미만이기때문에 for 3개 중첩
		for (int k1 = 0; k1 < base; k1++) {
			for (int k2 = 0; k2 < base; k2++) {
				for (int k3 = 0; k3 < base; k3++) {
					if ((k1 + k2 * base + k3 * base*base) % n == 0 && (k1 + k2 + k3) % n != 0) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
			}
			if (!ok) break;
		}
		if (ok) answer.push_back(n);
	}
	return answer;
}

public: vector <int> digit2(int base) {

	vector <int> answer;
	
	for (int n = 2; n < base; n++) {
		//전체 탐색 0,1 제외니까 2부터 base까지 돌면서 base-1을 나눠떨어지는 수와 그의 약수.
		if ((base - 1) % n == 0)
			answer.push_back(n);
	}
	return answer;
}
};

int main() {
	int base;

	cin >> base;
	InterestingDigits id = InterestingDigits();
	vector<int> answer = id.digits(base);
	vector<int> answer2 = id.digit2(base);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i]<<", ";
	}
	for (int i = 0; i < answer2.size(); i++)
	{
		cout << answer2[i] << ", ";
	}

	return 0;
}
