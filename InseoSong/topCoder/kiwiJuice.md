```C++
#include <vector>
#include <iostream>

using std::vector;

class kiwiJuiceEasy {
public: vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)

	{
		for (int i = 0; i < fromId.size(); i++) {
		
			int f = fromId[i];
			int t = toId[i];

			int space = capacities[i] - bottles[i];

			if (space >= bottles[f]) {
				int vol = bottles[f];
				bottles[f] += vol;
				bottles[f] = 0;
			}

			else {
				int vol = space;
				bottles[t] += vol;
				bottles[f] -= vol;
			}
		}
		return bottles;
	}
};

// int main() {
//	kiwiJuiceEasy input;

//}
```
