#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
//테스트케이스의 수
int t;
int main() {
	cin >> t;
	for (int i = 0; i < t; ++i) {
		//n ; 문서의 수, m : 인쇄 순서를 출력할 문서 
		int n, m;
		cin >> n >> m;
		//<문서 번호, 중요도> 쌍으로 큐에 저장 
		queue<pair<int, int>> q;
		//<중요도>로 우선순위 큐 저장
		priority_queue<int> pq;
		//문서 중요도 입력
		for (int doc = 0; doc < n; ++doc) {
			int priority;
			cin >> priority;
			q.push(make_pair(doc, priority));
			pq.push(priority);
		}
		int cnt = 0;
		while (!q.empty()) {
			int document = q.front().first;
			int priority = q.front().second;
			q.pop();
			if (pq.top() == priority) {
				cnt++;
				pq.pop();
				if (document == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push(make_pair(document, priority));
			}
		}
	}
	return 0;
}
