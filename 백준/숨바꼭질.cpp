#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
int bfs() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	vector<bool> discovered = vector<bool>(100001, false);
	int result = 0;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		discovered[here] = true;
		if (here == K) {
			result = cnt;
			break;
		}
		if (here - 1 >= 0 && !discovered[here - 1]) q.push({ here - 1, cnt + 1 });
		if (here + 1 <= 100000 && !discovered[here + 1]) q.push({ here + 1, cnt + 1 });
		if (2 * here <= 100000 && !discovered[2 * here]) q.push({ 2 * here, cnt + 1 });
 	}
	return result;
}
int main(void){
	cin >> N >> K;
	cout << bfs();
	return 0;
}