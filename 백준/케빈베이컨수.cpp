#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int N, M;
vector<vector<int>> map;
int main(void) {
	cin >> N >> M;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1));
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	//플로이드 모든쌍
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j) {
				if (i != j) {
					if (map[i][k] != 0 && map[k][j] != 0) {
						if (map[i][j] == 0) map[i][j] = map[i][k] + map[k][j];
						else map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
					}
				}
			}
	//케빈 베이컨 수 계산 
	vector<int> kb(N+1, 0);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			kb[i] += map[i][j];
	//최소값 뽑기
	int ret = 1;
	int max = 987654321;
	for (int i = 1; i <= N; ++i) {
		if (kb[i] < max) {
			ret = i;
			max = kb[i];
		}
	}
	cout << ret;
	
	return 0;
}