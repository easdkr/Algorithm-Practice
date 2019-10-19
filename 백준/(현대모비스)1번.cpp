#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int cache[100001];
void init_cache() {
	for (int i = 0; i < 100001; ++i)
		cache[i] = -1;
}
//남은 날짜가 days, 오늘 날짜가 today 일 때,
//가장 적게 비용이 드는 경우의 총액을 구하라 
int solve(int days, int today, int n, vector<int>& P) {
	if (days < 0) return 987654321;
	if (days == 0) return 0;
	int& ret = cache[days];
	if (ret != -1) return ret;
	//1번 사는 경우 
	ret = solve(days - 1, today+1, n, P) + P[today];
	//여러번 사는 경우 
	for (int i = 2; i <= n; ++i) {
		ret = min(ret, solve(days - i, today + i, n, P) + P[today] * i);
	}
	return ret;
}

int solution(int n, vector<int> P) {
	int answer = 0;
	answer = solve(n, 0, n, P);
	return answer;
}

int main(void){
	init_cache();
	int n = 10;
	vector<int> P = { 5,7,8,2,4,6,1,8,9,10 };
	cout << solution(n, P);
	return 0;
}