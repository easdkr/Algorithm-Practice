/*
* 두번째 접하는 같은 문제인데도 해결방법은 아리송하다
* 무게가 작은 추부터 추가하고
* 추의 누적합 sum을 계산하면서 (sum까지의 수는 어떤 방식으로든 만들 수 있다)
* 이번에 추가하는 추가 누적합 sum+1보다 큰 경우 
* sum+1이 측정할 수 없는 최소 정수가 된다. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<long long> weights;
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
    long long sum = 0; //누적합 
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for (auto w : weights) {
        if (sum + 1 >= w)
            sum += w;
        else
            break;
    }
    answer = sum + 1;
    cout << answer;
}
void input() {
    cin >> N;
    weights = vector<long long>(N);
    for (int i = 0; i < N; ++i)
        cin >> weights[i];
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
}
