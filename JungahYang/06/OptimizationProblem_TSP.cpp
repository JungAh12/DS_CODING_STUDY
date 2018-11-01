//� ���� n(2<=n<=10)���� ���ð� ���� ��,
//�� ���� ����� �� ���ÿ��� ����� �ٸ� ���õ��� ���� �ѹ��� �湮�ϰ� ���۵��÷� ���ƿ´�.
//�� ���õ��� ��� �������η� ����Ǿ��ִ�.
//���� ª����δ�?

//���۵��ô� 0, n-1���� ���ø� �湮�ؾ��Ѵ�. (n-1)!����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int dist[15][15];
int TSP(vector<int> path, vector<bool> visited, int len) {

	if (path.size() == n)
		return len + dist[path.back()][0];
	int ret = 999999999;

	for (int next = 0; next < n; ++next) {
	
		if (visited[next]) continue;

		int cur = path.back();
		path.push_back(next);
		visited[next] = true;
		ret = min(ret, TSP(path, visited, len + dist[cur][next]));
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	vector<int> path(1, 0);
	vector<bool> visited(n, false);
	visited[0] = true;
	int ret = TSP(path, visited, 0);
	cout << ret << endl;

}