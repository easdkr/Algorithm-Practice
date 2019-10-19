#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//회의의 수
int N;
//회의 시간을 <시작시간, 종료시간>의 쌍으로 저장 
vector<pair<int, int>> meeting;
//second값을 기준으로 오름차순 정렬한다.
bool compare(const pair<int, int>& a, const pair<int, int>& b);
//최대한 많이 배정받을 수 있는 회의의 수를 반환한다.
int solve();
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int start, end;
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}
	cout << solve() << "\n";
	return 0;
}
 
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solve() {
	int ret = 0;
	//회의 종료시간을 기준으로 정렬한다. 
	sort(meeting.begin(), meeting.end(), compare);
	//첫번째 회의 추가 
	ret++;
	//직전 회의의 종료시간 
	int prior = meeting[0].second;
	//두번째 부터 회의의 시작시간이 앞 회의의 종료시간 이후면 선택한다. 
	for (int i = 1; i < meeting.size(); ++i) {
		if (prior > meeting[i].first) continue;
		prior = meeting[i].second;
		++ret;
	}
	return ret;
}