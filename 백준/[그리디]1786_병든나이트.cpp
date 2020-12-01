/*
* https://do-rang.tistory.com/70 참고 
* 문제에 어색한 부분이 많다. 
* 추가되어야할 설명 : 이동 횟수가 4회 이상일 경우 
* 4가지의 이동방법을 모두 사용하지 않았다면 이동 할 수 없다.
* 제약이 없다라는 표현은 어색하다. 
* 
* 그림을 그려보면서 풀어봐야한다. (세로의 칸수에 따라서)
* 세로가 1 칸인 경우 : 현재 칸만 방문가능 (1)
* 세로가 2 칸인 경우 : 가로로 2칸씩 늘어날 때마다 방문 칸이 늘어나고, 
*                      이동 방법을 모두 사용하지 않으므로 4회 이상인 경우는 이동하지 않음
*                      min(4, (가로칸+1)/2)
* 세로가 3 칸 이상의 경우 : 
*   가로가 7칸 미만 : 이동방법 4가지 모두를 사용하는 방법이 없고, 가로로 한칸씩 이동하는게 최대
*                     min(4, M); 
*   가로가 7칸 이상 : 모든 이동 방법을 사용하려면 최소 7칸 필요 
*                     7칸 이상부터는 가로로 1칸씩 가능 
*                     (M-7) : 한칸씩 가능 횟수 + 5(7칸 까지의 이동횟수) 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M; //N : 세로, M : 가로 
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
    int answer = 0;
    //세로가 1칸 이면 현재 칸만 방문 가능
    if (N == 1) answer = 1;
    else if (N == 2)
        answer = min(4, (M + 1) / 2);
    else {
        if (M <= 6)
            answer = min(4, M);
        else
            answer = M - 2;
    }
    cout << answer;
}
void input() {
    cin >> N >> M;
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
}
