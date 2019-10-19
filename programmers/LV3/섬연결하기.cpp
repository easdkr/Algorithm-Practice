#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Greedy가 아니라 크루스컬 알고리즘 -최소 스패닝 트리 문제
const int MAX_V = 100;
//각 노드의 부모를 저장 - union-find 에 사용
int parent[MAX_V];
//각 집합의 깊이(rank)를 저장 - union-find에 사용 
int depth[MAX_V];
//cost를 기준으로 정렬
bool compare(vector<int>& a, vector<int>& b);

int find(int u);
void merge(int u, int v);

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
    //크루스컬알고리즘으로 최소 스패닝트리의 최소 가중치를 반환 
    //cost값을 기준으로 정렬한다. 
	sort(costs.begin(), costs.end(), compare);

	//parent, rank 초기화
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		depth[i] = 1;
	}
	
	//모든 간선을 검사한다. 
	for (int i = 0; i < costs.size(); ++i) {
		int cost = costs[i][2];
		int u = costs[i][0], v = costs[i][1];
		//사이클을 이루거나 이미 연결되어 있는 경우 무시
		if (find(u) == find(v)) continue;
        //병합한다. 
		merge(u, v);
		answer += cost;
	}

	return answer;
}

int find(int u) {
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (depth[u] > depth[v]) swap(u, v);
	parent[u] = v;
	if (depth[u] == depth[v]) ++depth[v];
}
bool compare(vector<int>& a, vector<int>& b) {
	return a[2] < b[2];
}