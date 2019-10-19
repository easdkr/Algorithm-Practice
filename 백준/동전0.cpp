#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> coin;
int main(void){
	cin >> N >> K;
	coin = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> coin[i];

	int cnt = 0;
	for (int i = coin.size() - 1; i >= 0; --i) {
		if (coin[i] <= K) {
			int r = K / coin[i];
			cnt += r;
			K -= (coin[i] * r);
		}
		if (K == 0) break;
	}
	cout << cnt;
	return 0;
}