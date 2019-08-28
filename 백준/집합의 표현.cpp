#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define UNION 0
#define FIND 1
//집합의 개수 
int n; 
//연산의 개수
int m;
struct disjointSet {
	vector<int> parent, rank;
	disjointSet(int n) {
		//초기 모든 원소의 부모는 자기 자신
		parent = vector<int>(n); 
		for (int i = 0; i < n; ++i)
			parent[i] = i;
		//초기 모든 길이는 1 
		rank = vector<int>(n, 1);
	}
	int find(int data) {
		if (data == parent[data]) return data;
		else return parent[data] = find(parent[data]);
	}

	void merge(int u, int v) {
		u = find(u), v = find(v);
		//이미 같다면 그냥 종료
		if (u == v) return;
		//v의 rank가 더 높게 유지 
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		//u와 v의 높이가 같다면 전체 높이 1 증가 
		if (rank[u] == rank[v]) rank[v]++;
	}
};
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	disjointSet dSet = disjointSet(n+1);
	for (int i = 0; i < m; ++i) {
		int cal, u, v;
		cin >> cal >> u >> v;
		if (cal == UNION) {
			dSet.merge(u, v);
		}
		else if (cal == FIND) {
			int setu = dSet.find(u), setv = dSet.find(v);
			if (setu == setv) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			cout << "OOPS\n";
		}
	}
	return 0;
}
