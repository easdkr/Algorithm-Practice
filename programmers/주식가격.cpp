#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer = vector<int>(prices.size(), 0);
	//이전의 주식가격(인덱스)을 담을 스택 
	stack<int> s;
	for (int i = 0; i < prices.size(); ++i) {
		//현재 주식 가격(인덱스)  
		int curr = i;
		while (!s.empty()) {
			int prior = s.top();
			//현재 주식 가격이 이전 주식가격보다 떨어졌으면
			//stack에서 빼낸다. 
			if (prices[prior] > prices[curr]) {
				answer[prior] = curr - prior;
				s.pop();
			}
			else break;
		}
		s.push(curr);
	}
	//스택에 남아있는 것 처리 
	while (!s.empty()) {
		int curr = s.top();
		answer[curr] = prices.size() - curr -1;
		s.pop();
	}
	return answer;
}

int main(void) {
	vector<int> prices = { 1, 2, 3, 2, 3 };
	for (auto i : solution(prices))
		cout << i << " ";
	return 0;
}
