#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int move_y[4] = { 1, -1, 0, 0 };
const int move_x[4] = { 0, 0, 1, -1 };
//N : 세로 크기, M : 가로 크기
int N, M;
//원래 연구실 지도 
vector<vector<int>> original_map;
//각 상황 별로 계산을 위해 복사할 연구실 지도 
vector<vector<int>> copied_map;
//감염된 지도 저장 
vector<vector<int>> infected_map;
//초기 바이러스의 위치
vector<pair<int, int>> virus_position;
//결과 값(안전 영역의 최대 크기)
int ret = 0;

//map 범위를 벗어나면 true, 아니면 false를 반환 
bool outOfRange(int y, int x);
//연구실 지도 복사 
void copy_map(vector<vector<int>>& target, vector<vector<int>>& base);
//현재까지 세운 벽의 개수가 cnt개 일 때, 
//cnt == 3이 될때까지 임의의 위치에 벽을 세우고, 
//cnt == 3이면 바이러스가 퍼진 지도를 만든다. 
void install_wall(int cnt);
//BFS 탐색을 진행하며 퍼진 바이러스의 지도를 구하고
//안전영역의 크기를 구한다. 
void bfs();
//안전영역의 크기 구하기 
int getSafetyZone();
int main(void){
	cin >> N >> M;
	original_map = vector<vector<int>>(N, vector<int>(M));
	copied_map = vector<vector<int>>(N, vector<int>(M));
	infected_map = vector<vector<int>>(N, vector<int>(M));
	//지도 입력 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {

			cin >> original_map[i][j];
			if (original_map[i][j] == 2)
				//초기 바이러스 위치 저장 
				virus_position.push_back(make_pair(i, j));
		}
	}
	//전체 map에서 세울 수 있는 모든 곳에 벽을 세우며(브루트 포스) 
	//최대 안전 지대의 크기를 구한다. 
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			//벽을 세울 수 있는 곳이면 
			if (original_map[y][x] == 0) {
				//연구실 지도 복사 
				copy_map(copied_map, original_map);
				//첫번째 벽을 세운다
				copied_map[y][x] = 1;
				//재귀적으로 나머지 2개의 벽을 추가해 3개의 벽을 만들고
				//바이러스에 감염된 지도를 만든다. 
				install_wall(1);
				//현재 위치에 벽을 안만들었다고 가정한다. 
				copied_map[y][x] = 0;
			}
		}
	}
	cout << ret;
	return 0;
}
//map 범위를 벗어나면 true, 아니면 false를 반환 
bool outOfRange(int y, int x) {
	if (y >= N || y < 0 || x >= M || x < 0)
		return true;
	return false;
}

//연구실 지도 복사 
void copy_map(vector<vector<int>>& target, vector<vector<int>>& base) {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			target[y][x] = base[y][x];
		}
	}
}

//현재까지 세운 벽의 개수가 cnt개 일 때, 
//cnt == 3이 될때까지 임의의 위치에 벽을 세우고, 
//cnt == 3이면 바이러스가 퍼진 지도를 만든다. 
void install_wall(int cnt) {
	if (cnt == 3) {
		bfs();
		ret = max(ret, getSafetyZone());
		return;
	}
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (copied_map[y][x] == 0) {
				copied_map[y][x] = 1;
				install_wall(cnt + 1);
				copied_map[y][x] = 0;
			}
		}
	}
}

//BFS 탐색을 진행하며 퍼진 바이러스의 지도를 만든다. 
void bfs() {
	copy_map(infected_map, copied_map);
	queue<pair<int, int>> q;
	for (int i = 0; i < virus_position.size(); ++i)
		q.push(make_pair(virus_position[i].first, virus_position[i].second));
	//감염 진행
	while (!q.empty()) {
		int hereY = q.front().first, hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int thereY = hereY + move_y[i], thereX = hereX + move_x[i];
			if (!outOfRange(thereY, thereX) && infected_map[thereY][thereX] == 0) {
				infected_map[thereY][thereX] = 2;
				q.push(make_pair(thereY, thereX));
			}
		}
			
	}
}

//안전영역의 크기 구하기 
int getSafetyZone() {
	int area = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (infected_map[y][x] == 0)
				area++;
		}
	}
	return area;
}