#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
struct compare {
	bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
		if (a.first != b.first) return a.first > b.first;
		else return a.second < b.second;
	}
};

string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	string answer = "";
	//<-적산주행거리, 차량번호> 쌍으로 우선순위큐를 생성
	priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
	for (int i = 0; i < n; ++i) 
		pq.push(make_pair(odo[i], plates[i]));
	
	for (int i = 0; i < k; ++i) {
		//우선순위가 높은 = 적산주행거리가 가장 짧은 것부터 
		//대여를 시작한다. 
		int car_odo = -pq.top().first;
		string car_name = pq.top().second;
		pq.pop();
		//주행거리 계산 
		car_odo += drives[i];
		//다시 우선순위 큐에 삽입
		pq.push(make_pair(-car_odo, car_name));
	}
	//다음 고객에게 대여할 차량 = 우선순위큐의 top

	answer = pq.top().second;
	return answer;
}
int main(void){
	
	return 0;
}