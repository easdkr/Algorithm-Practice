#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;
int n;
int m;
#define MAX_CHANNEL 999900

bool broken[10];
int solution();
bool isPossibleChannel(int channel);
int main(void) {
	//입력값 초기화 
	cin >> n;
	cin >> m;
	for (int i = 0; i < 10; ++i)
		broken[i] = false;
	for (int i = 0; i < m; ++i) {
		int temp; 
		cin >> temp;
		broken[temp] = true;
	}

	cout << solution() << "\n";
	return 0;
}


int solution() {
	//ret 초기 값은 n - 100 : +나 -로 이동할 수 있는 클릭수 
	int ret = max(n,100) - min(n, 100);
	// 0번 부터 499900번까지 몇 번의 클릭수가 필요한지 체크한다.
	for (int channel = 0; channel < MAX_CHANNEL; ++channel) {
		if (isPossibleChannel(channel))
			ret = min(ret, max(n, channel) - min(n, channel) + int(to_string(channel).size()));
	}
	return ret;
}

bool isPossibleChannel(int channel) {
	string sChannel = to_string(channel);
	for (int digit = 0; digit < sChannel.size(); ++digit) {
		if (broken[sChannel[digit] - '0']) return false;
	}
	return true;
}