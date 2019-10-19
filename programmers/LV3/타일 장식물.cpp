#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
그림의 둘레를 계산해보면 
N 단계의 정사각형의 둘레는 
N-1 단계의 정사각형의 둘레 + N-2 단계의 정사각형의 둘레이다. 
*/
long long solution(int N) {
    long long answer = 0;
    long long cache[N+1]; 
    cache[1] = 4; 
    cache[2] = 6;
    for(int i = 3; i <= N; ++i){
        cache[i] = cache[i-1] + cache[i-2];
    }
    answer = cache[N];
    return answer;
}

int main(void){
    cout << solution(5);
}