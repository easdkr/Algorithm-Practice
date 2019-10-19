#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//N : 정점의 개수, M : 간선의 개수 
int N, M;
//방문 여부 
vector<int> visited;
//인접 리스트 
vector<vector<int>> adj;
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}
int dfsAll() {
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}
int main(void){
	cin >> N >> M;
	visited = vector<int>(N + 1, false);
	adj = vector<vector<int>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << dfsAll();
	return 0;
}