/*
* https://do-rang.tistory.com/70 ���� 
* ������ ����� �κ��� ����. 
* �߰��Ǿ���� ���� : �̵� Ƚ���� 4ȸ �̻��� ��� 
* 4������ �̵������ ��� ������� �ʾҴٸ� �̵� �� �� ����.
* ������ ���ٶ�� ǥ���� ����ϴ�. 
* 
* �׸��� �׷����鼭 Ǯ������Ѵ�. (������ ĭ���� ����)
* ���ΰ� 1 ĭ�� ��� : ���� ĭ�� �湮���� (1)
* ���ΰ� 2 ĭ�� ��� : ���η� 2ĭ�� �þ ������ �湮 ĭ�� �þ��, 
*                      �̵� ����� ��� ������� �����Ƿ� 4ȸ �̻��� ���� �̵����� ����
*                      min(4, (����ĭ+1)/2)
* ���ΰ� 3 ĭ �̻��� ��� : 
*   ���ΰ� 7ĭ �̸� : �̵���� 4���� ��θ� ����ϴ� ����� ����, ���η� ��ĭ�� �̵��ϴ°� �ִ�
*                     min(4, M); 
*   ���ΰ� 7ĭ �̻� : ��� �̵� ����� ����Ϸ��� �ּ� 7ĭ �ʿ� 
*                     7ĭ �̻���ʹ� ���η� 1ĭ�� ���� 
*                     (M-7) : ��ĭ�� ���� Ƚ�� + 5(7ĭ ������ �̵�Ƚ��) 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M; //N : ����, M : ���� 
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
    //���ΰ� 1ĭ �̸� ���� ĭ�� �湮 ����
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
