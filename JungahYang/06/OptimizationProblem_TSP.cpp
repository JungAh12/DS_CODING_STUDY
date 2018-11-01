//어떤 나라에 n(2<=n<=10)개의 도시가 있을 때,
//한 영업 사원이 한 도시에서 출발해 다른 도시들을 전부 한번씩 방문하고 시작도시로 돌아온다.
//각 도시들은 모두 직선도로로 연결되어있다.
//가장 짧은경로는?

//시작도시는 0, n-1개의 도시를 방문해야한다. (n-1)!가지

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