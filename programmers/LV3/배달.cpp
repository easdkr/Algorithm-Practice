#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 50;
const int INF = 987654321;
//그래프의 인접리스트 adj[i] : <i와 연결된 정점, (i, j)의 가중치>
vector<pair<int, int>> adj[MAX_V + 1];

void toAdjList(vector<vector<int>> road);
vector<int> dijkstra(int start, int N);

// param : N(마을의 개수), road(도로의 정보), K(음식 배달이 가능한 시간)
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	toAdjList(road);
	vector<int> ret = dijkstra(1, N);
	for (int i = 0; i < ret.size(); ++i)
		if (ret[i] <= K)
			answer++;
	return answer;
}

void toAdjList(vector<vector<int>> road) {
	for (int i = 0; i < road.size(); ++i) {
		int u = road[i][0];
		int v = road[i][1];
		int w = road[i][2];
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
}
vector<int> dijkstra(int start, int N) {
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	//<현재까지 찾은 최단 거리, 정점>저장
	priority_queue<pair<int, int>> max_heap;
	max_heap.push(make_pair(0, start));

	while (!max_heap.empty()) {
		int curr_dist = -max_heap.top().first;
		int here = max_heap.top().second;
		max_heap.pop();
		//만약 지금꺼낸 경로보다 더 짧은 경로를 안다면 그냥 패스
		if (curr_dist > dist[here]) continue;
		//인접한 정점을 검사한다. 
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int there_dist = adj[here][i].second + curr_dist;
			//더 짧은 경로를 발견했다면 
			if (dist[there] > there_dist) {
				dist[there] = there_dist;
				max_heap.push(make_pair(-there_dist, there));
			}
		}
	}
	return dist;
}