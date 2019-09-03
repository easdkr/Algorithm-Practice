#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long mod = 1000000007;
//fact[n] : n!
long long fact[4000001];
//inv[n] : x!^(-1)
long long inv[4000001];
//n^size의 값을 반환한다.
long long pow(long long n, long long size);
//1부터 4000000까지 factorial 값을 구한다. 
void init_fact();
//페르마의 소정리를 이용하여 이항계수를 구한다. 
long long bino(int n, int k);
//***** 재귀를 이용한 pow함수로는 시간이 너무 오래걸려서 안됐다.*******
int main(void) {
	init_fact();
	long long n, k;
	cin >> n >> k;
	cout << bino(n, k) << "\n";
	return 0;
}
//페르마의 소정리 : n^(p-1) mod p 와 1은 mod p에 대해 합동이다. 
//페르마의 소정리를 이용하여 이항계수를 구한다. 
long long bino(int n, int k) {
	long long ret = 0;
	//n^(p-2) mod p는 n^(-1)과 합동이다. 
	//bino(n, k) = n!/k!*(k-n)! = n! * (k!*(k-n)!)^(-1) = 
	// = n! * (k!*(k-n)!)^(p-2)
	long long a = fact[n];
	long long b = (fact[k] * fact[n - k]) % mod;
	b = pow(b, mod - 2) % mod;
	ret = (a * b) % mod;
	return ret;
}
//n^size의 값을 반환한다. 
//long long pow(long long n, long long size) {
//	long long ret = 0;
//	if (size == 1) return n % mod;
//	if (size % 2 == 1)
//		ret = ((pow(n, size / 2) % mod) * (pow(n, size / 2) % mod) * n) % mod;
//	else
//		ret = (pow(n, size / 2) % mod * pow(n, size / 2) % mod) % mod;
//	return ret;
//}
long long pow(long long x, long long y) {
	long long ret = 1;
	while (y > 0) {
		if (y % 2 == 1)
			ret = (ret * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return ret;
}
//1부터 4000000까지 factorial 값을 구한다. 
void init_fact() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 4000000; ++i)
		fact[i] = ((fact[i - 1] % mod) * i) % mod;
}