#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> t, p;
int cache[16];
void init_cache() {
	for (int i = 0; i < 16; ++i)
		cache[i] = -1;
}
int solve(int days) {
	if (days == n) return 0;
	if (days > n) return -987654321;
	int& ret = cache[days];
	if (ret != -1) return ret;
	ret = max(solve(days + t[days]) + p[days], solve(days + 1));
	return ret;
}
int main(void){
	cin >> n;
	t = vector<int>(n + 1);
	p = vector<int>(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> t[i] >> p[i];
	init_cache();
	cout << solve(0);
	return 0;
}