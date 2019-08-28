#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> cache;
long long a, b, c;
//void init_cache(int size) {
//	cache = vector<int>(size+1, -1);
//}

long long mux(int b) {
	long long ret = 0;
	if (b == 1) return a % c;
	/*
	int& ret = cache[b];
	if (ret != -1) return ret;
	*/
	if (b % 2 == 1)
		ret = (mux(b / 2) %c * mux(b / 2) %c * a) % c;
	else
		ret = (mux(b / 2) % c * mux(b / 2) % c) % c;
	return ret;
}
int main(void) {
	cin >> a >> b >> c;
	//init_cache(b);
	cout << mux(b) << "\n";
	return 0;
}
