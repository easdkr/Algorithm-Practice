#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//단지 수 
int N;
//지도 
vector<vector<bool>> board;
//결과값을 저장할 벡터 
vector<int> result;
//지역의 방문 여부 저장 
vector<vector<bool>> visited;

//이동할 수 있는 부분을 탐색하기 위한 배열
//위, 아래, 오른쪽, 왼쪽 
const int move_y[4] = { -1, 1, 0, 0 };
const int move_x[4] = { 0, 0, 1, -1 };
//범위가 벗어났으면 true, 안벗어났으면 false
bool outOfRange(int y, int x);
//here에서 부터 bfs를 수행하고 그룹(컴포넌트)의 크기를 반환한다. 
int bfs(int y, int x);
//전체 문제를 해결한다
void solve();
int main(void) {
	//단지 수 입력
	cin >> N;
	//지도 입력 
	board = vector<vector<bool>>(N, vector<bool>(N, 0));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; ++i) {
		string input; 
		cin >> input;
		for (int j = 0; j < N; ++j) {
			if (input[j] == '1') board[i][j] = true;
			else board[i][j] = false;
		}
	}
	solve();
	return 0;
}

void solve() {
	//지도의 모든 부분을 탐색하며
	//아직 방문하지 않고, true 인 점을 발견하면 bfs를 실행한다. 
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && board[i][j]) {
				result.push_back(bfs(i, j));
				//cout << bfs(i,j);
			}
			visited[i][j] = true;
			//cout << i << ", " << j << " ";
		}
	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "\n";
}

int bfs(int y, int x) {
	//count : 그룹의 크기를 저장 
	int count = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	count++;
	while (!q.empty()) {
		pair<int, int> here = q.front(); q.pop();
		visited[y][x] = true;
		
		for(int i = 0; i < 4; ++i) {
			int next_y = here.first + move_y[i], next_x = here.second + move_x[i];
			//범위 내에 있고, 방문하지 않고, 집이 있는 곳이면 큐에 추가하고 그룹의 크기 증가
			if (!outOfRange(next_y, next_x) && !visited[next_y][next_x]
				&& board[next_y][next_x]) {
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = true;
				++count;
			}
		}
	}
	return count;
}
bool outOfRange(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)
		return true;
	return false;
}


