/*입력리스트에서 1개의 값을 선택하고 1을 증가시킨다.
이때 내부의 모든 숫자 곱이 가장 커야한다.
int[] number 형태로 숫자 배열이 주어질때 곱의 최댓값을 리턴하라.

class : Cryptography
c++ : public : long long encrypt(vector <int> numbers)*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cryptography {
	long long select = 0;
public: long long encrypt(vector <int> numbers) {
		for (int i = 0; i < numbers.size(); i++) {
			long long result = 1;
			++numbers[i];
			for (int j = 0; j < numbers.size(); j++) {
				result *= numbers[j];
			}
			--numbers[i];
			select = max(result, select);
			
		}
		return select;
	};
};

int main() {

	vector <int> numbers = vector <int>();
	string str;
	int end;
	getline(cin, str);
	for (int i = 0; i <= str.length();) {		
		end = str.find(',', i);
		numbers.push_back(atoi(str.substr(i, end-i).c_str()));
		i = end + 1;
		if (i == 0)break;
		//numbers.push_back(atoi(str.substr(',',i).c_str()));
		//cout << numbers[i];
	}
	Cryptography c = Cryptography();
	cout << c.encrypt(numbers);
	return 0;
}
