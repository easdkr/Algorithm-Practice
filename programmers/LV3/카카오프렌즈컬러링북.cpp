#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> move_y;
vector<int> move_x;

bool outOfRange(int y, int x, int m, int n);
vector<int> bfs(int n, int m, vector<vector<int>> picture);

// m : 가로크기 n : 세로 크기 
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	move_y = { -1, 1, 0, 0 };
	move_x = { 0, 0, 1, -1 };

	vector<int> answer(2);
	answer = bfs(m, n, picture);
	return answer;
}
int main(void) {
	int m = 6;
	int n = 4;
	vector<vector<int>> picture =
	{
	 {1, 1, 1, 0},
	 {1, 2, 2, 0},
	 {1, 0, 0, 1},
	 {0, 0, 0, 1},
	 {0, 0, 0, 3},
	 {0, 0, 0, 3}
	};
	vector<int> ret = solution(m, n, picture);
	for (auto i : ret) cout << i << " ";
	return 0;
}

vector<int> bfs(int m, int n, vector<vector<int>> picture) {
	//ret[0] : 영역의 개수, ret[1] : 최대 영역의 크기 
	vector<int> ret = { 0,0 };
	//최대 영역의 크기를 저장 
	queue<pair<int, int>> q;
	vector<vector<bool>> discovered = vector<vector<bool>>(m, vector<bool>(n, false));

	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			int area = 0;
			if (picture[y][x] != 0 && discovered[y][x] == false) {
				ret[0]++;
				
				area++;
				int color = picture[y][x];
				q.push(make_pair(y,x));
				discovered[y][x] = true;
				
				while (!q.empty()) {
					pair<int, int> here = q.front(); 
					q.pop();
					for (int i = 0; i < 4; ++i) {
						int next_y = here.first + move_y[i], next_x = here.second + move_x[i];
						//cout << next_y << " " << next_x << "\n";
						if (!outOfRange(next_y, next_x, m, n) && picture[next_y][next_x] == color &&
							!discovered[next_y][next_x]) {
							q.push(make_pair(next_y, next_x));
							discovered[next_y][next_x] = true;
							area++;
						}
					}
				}
				//최대영역의 크기 갱신 
				ret[1] = max(ret[1], area);
			}
		}
	}
	
	return ret;
}

bool outOfRange(int y, int x, int m, int n) {
	if (y >= m || y < 0 || x >= n || x < 0)
		return true;
	return false;
}