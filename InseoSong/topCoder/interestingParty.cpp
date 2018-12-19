using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int interest(vector<string>& first, vector<string>& second) {
	int currMax = 1;
	for (int i = 0; i < first.size(); i++) {
		int curr = 0;
		string interest = first[i];
		for (string f : first) {
			if (f == interest) curr++;
		}
		for (string s : second) {
			if (s == interest) curr++;
		}
		if (curr > currMax) currMax = curr;
		if (curr >= first.size()) {
			currMax = curr;
			break;
		}
	}
	return currMax;
}

int main() {

	vector<string> input1_first = { "a", "g", "s", "f" };
	vector<string> input1_second = { "h", "f", "f", "b" };

	cout << interest(input1_first, input1_second) << endl;
	return 0;
}
