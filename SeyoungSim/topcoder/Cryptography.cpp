#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void encrypt(vector<int> &numbers)
{
	int m = 0;

	for (int i = 0; i < numbers.size(); i++) {

		int sum = 1;
		numbers[i] = numbers[i] + 1; // i번째 배열의 원소에 +1해줌

		for (int j = 0; j < numbers.size(); j++) {
			sum *= numbers[j];
		}

		m = max(sum, m); // 최대값을 찾음

		numbers[i] = numbers[i] - 1; // +1해준 원소를 제자리로 돌려놓음
	}

	cout << m << endl;

}

void main(void) {

	string str="";
	vector<int> numbers = vector<int>();

	cout << "숫자 배열 입력: ";

	getline(cin, str); // 문자열은 cin으로 받을 수 없음

	for (int i = 0; i < str.length(); i++) {

		if (i % 2 == 0)
			numbers.push_back(atoi(str.substr(i,i+1).c_str()));
			// atoi이용시 () 안에 char* 들어가야함 -> c_str()이용하여 str을 char*로 변환
			// str[i].c_str() 오류 발생(=원소접근 불가) -> substr() 사용하여 문자열 자르는 방법을 사용
	}

	/*for (int i = 0; i < numbers.size(); i++) { // 배열에 제대로 들어갔는지 check
		cout << numbers[i] << " ";
	}*/

	encrypt(numbers); // 함수에 배열을 넘겨줌
	
}
