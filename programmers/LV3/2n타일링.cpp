#include <string>
#include <vector>

using namespace std;
long long cache[60001];
const long long mod = 1000000007;
void init_cache();
long long tiling(int n);
int solution(int n) {
    int answer = 0;
    init_cache();
    return answer = tiling(n);
}
long long tiling(int n){
    //기저 사례 1
    if(n < 0) return 0;
    //기저 사례 2
    if(n == 0) return 1;
    //메모이제이션
    long long& ret = cache[n];
    if(ret != -1) return ret;
    ret = tiling(n-1) %mod + tiling(n-2) %mod;
    return ret % mod;
}
void init_cache(){
    for (int i = 0; i <= 60000; ++i)
        cache[i] = -1;
}