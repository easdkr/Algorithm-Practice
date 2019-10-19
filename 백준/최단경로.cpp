#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_V = 20001;
const int INF = 987654321;
//그래프의 인접리스트 adj[i] = <i와 연결된 정점, (i,j)의 가중치> 
vector<pair<int, int>> adj[MAX_V];
//V : 정점의 개수, E : 간선의 개수 
int V, E;
//시작 정점의 번호
int K;
//start에서 부터 모든 정점까지 최단 거리를 구한다. 
vector<int> dijkstra(int start);
int main(void) {
	//정점과 간선의 개수 입력
	cin >> V >> E;
	//시작 정점 입력 
	cin >> K;
	//간선 입력 
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	vector<int> dist = dijkstra(K);
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INF) cout << "INF";
		else cout << dist[i];
		cout << "\n";
	}
	
	return 0;
}

vector<int> dijkstra(int start) {
	vector<int> dist(V + 1, INF);
	//<현재까지 찾은 최단 거리, 정점> 저장
	dist[start] = 0;
	priority_queue<pair<int, int>> max_heap;
	max_heap.push(make_pair(0, start));
	while (!max_heap.empty()) {
		int curr_dist = -max_heap.top().first;
		int here = max_heap.top().second;
		max_heap.pop();
		//만약 지금 꺼낸 경로보다 더 짧은 경로를 안다면 그냥 패스
		if (curr_dist > dist[here]) continue;
		//인접 정점 검사 
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int next_dist = adj[here][i].second + curr_dist;
			//더 짧은 경로를 발견했으면 
			if (dist[there] > next_dist) {
				dist[there] = next_dist;
				max_heap.push(make_pair(-next_dist, there));
			}
		}
	}
	return dist;
}

