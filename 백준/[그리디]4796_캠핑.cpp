/*
* 그리디 접근 : 연속하는 P중 L만큼 사용하여 캠핌장 사용날짜를 최대화하려면
* 사용할 수 있을 때마다 L 만큼 사용하고, P-L만큼은 쉬어야한다. 
* 수학적 접근 : V일동안 P번이 등장하는 횟수 X L + 나머지 날짜 중 사용할 수 있는 횟수
*  = (V/P)*L + V%P(이때 V%P가 L보다 크다면 L) 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int P; //연속하는 기준 날짜
int L; //P일중 사용할 수 있는 날짜 
int V; //휴가 전체 일수 
void solve();
void input();
void init();
int main(void) {
    init();
    input();
    solve();
    return 0;
}
void solve() {
    int idx = 1;
    while (true) {
        cin >> L >> P >> V;
        if (P == 0 && L == 0 && V == 0) return;
        int answer = (V / P) * L;
        answer += (V % P) >= L ? L : (V % P);
        cout << "Case " << idx << ": " << answer << "\n";
        idx++;
    }
}
void input() {
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
}
