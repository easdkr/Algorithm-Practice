#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cache[5001];
void init() {
	for (int i = 0; i <= 5000; ++i)
		cache[i] = -1;
}
int solve(int weights) {
	if (weights > n) return 987654321;
	if (weights == n) return 0;
	int& ret = cache[weights];
	if (ret != -1) return ret;
	ret = min(solve(weights + 3), solve(weights + 5)) + 1;
	return ret;
}
int main(void){
	cin >> n;
	init();
	//987654321-5000: 대충 설정한 max값이라고 보면된다. 
	if (solve(0) < 987654321 - 5000)
		cout << solve(0);
	else
		cout << -1;
	return 0;
}