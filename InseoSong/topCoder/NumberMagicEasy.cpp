#include <iostream>
#include <string>
using namespace std;

const string cards[4] = { "YYYYYYYYNNNNNNNN" ,"YYYYNNNNYYYYNNNN" , "YYNNYYNNYYNNYYNN" ,"YNYNYNYNYNYNYNYN" };

class NumberMagicEasy {

public:	
	NumberMagicEasy(){
		string input;
		getline(cin, input);

		cout << findNumber(input) << endl;
	}

	int findNumber(string input) {
	
		for (int i = 0; i < 16; i++) {
			if (input[0]==cards[0][i] &&
			    input[1]==cards[1][i] &&
			    input[2]==cards[2][i] &&
			    input[3]==cards[3][i]) return i+1;
		}
	}
};

int main() {

	NumberMagicEasy* notEasyTT = new NumberMagicEasy;
	return 0;
}
