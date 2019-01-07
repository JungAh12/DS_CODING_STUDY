#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> friends = { "NNN", "NNN", "NNN" };
vector<bool> isFriend;
vector<int> scores;
bool check = false;

inline int friendScore(string friendsList) {
	int score = 0;
	int except = 0;
	for (int i = 0; i < friendsList.length(); i++) {
		if (friendsList[i] == 'Y') {
			score++;
			if (check&&isFriend[i]) except++;
		}
	}
	return score-except;
}

int main() {
	vector<int> NumOfFriends;
	int max=0;
	int result = 0;

	for (int i = 0; i < friends.size(); i++) {
		int currentScore = friendScore(friends[i]);
		scores.push_back(currentScore);
		if (currentScore >= max) {
			result = currentScore;
			max = i;
		}
	}
	for (int i = 0; friends[max].length(); i++) {
		if (friends[max][i] == 'Y') {
			isFriend.push_back(true);
		}
		else isFriend.push_back(false);
	}
	check = true;

	for (int i = 0; i < isFriend.size(); i++) {
		if (isFriend[i]) result += friendScore(friends[i]);
	}
	
	cout << result << endl;

	return 0;
}
