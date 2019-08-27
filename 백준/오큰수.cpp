#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//n : 입력의 개수 
int n;
//인풋 벡터
vector<int> input;
//결과 벡터
vector<int> ret;
//입력이 0이면 pop한다. 
void nge() {
	ret = vector<int>(n);
	//오큰수를 결정하지 못한 수(인덱스)를 저장하는 스택
	stack<int> s;
	//큐 초기화
	queue<int> q;
	for (int i = 0; i < n; ++i) q.push(i);
	//큐가 다 비워질때까지 
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
		//큐가 다 비워졌으면 스택에 남은 수의 오큰수를 -1로 결정한다. 
		if (q.empty()) {
			while (!s.empty()) {
				ret[s.top()] = -1;
				s.pop();
			}
			break;
		}
		//q front의 수가 stack의 수보다 크면 오큰수로 결정한다.  
		while (!s.empty() && input[s.top()] < input[q.front()]) {
			ret[s.top()] = input[q.front()];
			s.pop();
		}
	}
	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << "\n";
}
int main(void) {
	cin >> n; 
	input = vector<int>(n);
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	nge();
	return 0;
}
