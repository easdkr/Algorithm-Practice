#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V = 1000001;
//정점의 개수 
int V;
//adj[i] : <연결된 정점, 간선의 길이>
vector<pair<int, int>> adj[MAX_V];
//트리의 지름을 담을 변수 
int length;
//dfs 방문 여부 저장 
vector<bool> visited;
//루트에서 가장 먼 리프 노드 
int furthermost_node;
//최장 길이
int longest;
//가장 먼 리프 노드를 구하는 dfs
void dfs(int here, int dist);
//지름을 구하는 dfs
int dfs(int here);
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V;
	for (int i = 0; i < V; ++i) {
		int a; 
		cin >> a;
		while (true) {
			int vertex, weight;
			cin >> vertex;
			if (vertex == -1) break;
			cin >> weight;
			adj[a].push_back(make_pair(vertex, weight));
		}
	}
	//방문여부 배열 초기화 
	visited = vector<bool>(MAX_V, false);
	//루트로 부터 가장 먼 리프 노드를 구한다. 
	longest = 0;
	dfs(1, 0);
	//방문여부 배열 재 초기화 
	visited.clear();
	visited = vector<bool>(MAX_V, false);
	//루트에서 가장 먼 리프노드에서 지름을 구한다. 
	cout << dfs(furthermost_node) << "\n";
	return 0;
}
int dfs(int here) {
	int ret = 0;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i].first;
		int weight = adj[here][i].second;
		if (!visited[there]) {
			ret = max(ret, dfs(there) + weight);
		}
	}
	return ret;
}
void dfs(int here, int dist) {
	visited[here] = true;
	if (dist > longest) {
		longest = dist;
		furthermost_node = here;
	}
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i].first;
		int weight = adj[here][i].second;
		if (!visited[there]) {
			dfs(there, dist + weight);
		}
	}
}
