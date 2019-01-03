#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace::std;

int findFriends(vector<string>Flist) {
	int num = 0;
	int result = 0;
	for (int i = 0; i < Flist.size()-1; i++) {
		num = 0;
		for (int j = 0; j < Flist.size(); j++) {
			if (i==j)
				continue;
			if (Flist[i][j] == 'Y')
				++num;
			else {
				for (int k = 0; k < Flist.size(); k++) {
					if (Flist[k][i] == 'Y' && Flist[j][k] == 'Y') {
						++num;
					}
				}
			}
		}
		result = max(num, result);
	}
	return num;
}
