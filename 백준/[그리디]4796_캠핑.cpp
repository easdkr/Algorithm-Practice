/*
* �׸��� ���� : �����ϴ� P�� L��ŭ ����Ͽ� ķ���� ��볯¥�� �ִ�ȭ�Ϸ���
* ����� �� ���� ������ L ��ŭ ����ϰ�, P-L��ŭ�� ������Ѵ�. 
* ������ ���� : V�ϵ��� P���� �����ϴ� Ƚ�� X L + ������ ��¥ �� ����� �� �ִ� Ƚ��
*  = (V/P)*L + V%P(�̶� V%P�� L���� ũ�ٸ� L) 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int P; //�����ϴ� ���� ��¥
int L; //P���� ����� �� �ִ� ��¥ 
int V; //�ް� ��ü �ϼ� 
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
