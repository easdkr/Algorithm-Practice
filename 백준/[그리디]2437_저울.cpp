/*
* �ι�° ���ϴ� ���� �����ε��� �ذ����� �Ƹ����ϴ�
* ���԰� ���� �ߺ��� �߰��ϰ�
* ���� ������ sum�� ����ϸ鼭 (sum������ ���� � ������ε� ���� �� �ִ�)
* �̹��� �߰��ϴ� �߰� ������ sum+1���� ū ��� 
* sum+1�� ������ �� ���� �ּ� ������ �ȴ�. 
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
    long long sum = 0; //������ 
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
