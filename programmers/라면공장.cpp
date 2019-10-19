#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//최대힙 
priority_queue<int, vector<int>> pq;
int solution(int stock, vector<int> dates, vector<int> supplies, int k);
int main(void) {
	int stock = 4;
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20, 5, 10 };
	int k = 30;
	cout << solution(stock, dates, supplies, k);
	return 0;
}
//현재 heap에서 가장 큰 양의 밀가루를 공급받는다. 
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int supp_date = 0;
	for (int i = 0; i < k; ++i) {
		//새벽에 공급 받는 단계
			//공급받을 수 있는 날이면 heap에 담는다. 
		if (i == dates[supp_date]) {
			pq.push(supplies[supp_date]);
			supp_date = supp_date < supplies.size()-1 ? supp_date+1 : supp_date;
		}
		//현재 재고가 비어있는 경우 
		if (stock == 0) {
			stock += pq.top(); pq.pop();
			answer++;
		}
		//오늘 소비하는 단계
		stock--;
	}
	return answer;
}