/*
���ڿ� + ��Ʈ��ŷ �����̴�. 
K�� ��ŭ ���ĺ��� �����ƴٰ� �����Ҷ�, 
�־��� N���� �ܾ� �� K���� ���ĺ������� �̷���� �ܾ��� ������ ���Ѵ�, 
�� �� �ܾ��� ������ �ִ�ȭ�ϴ� K���� ������ ã�� �ִ� �ܾ��� ������ ���ؾ��Ѵ�. 

������ �ᱹ 
K�� ���ĺ����� ��� ������ ã��(back tracking)�̿� 
������ �ϼ��Ǹ�, �ܾ �˻��Ͽ� �ش� �������θ� �̷���� �ܾ� ã���̴�. 

������ ��)
a, n, t, i, c�� ������ �����ľ��ϴ� ���ĺ��̴�.
 - K�� 5 �����̸� ��� �� �ִ� �ܾ ���� : 0 ���
K�� 26�̸� ��� �ܾ ��� �� �ִ� : N ��� 
��� �ܾ ���λ� anta, ���̻� tica�� �����̹Ƿ� 
�Է� ���ڿ����� �������ش�. 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N; //�ܾ��� ���� 
int K; //�����ľ��� ����(���ĺ�)�� ���� 
vector<bool> taught; //����ģ ���ĺ� üũ
vector<string> words;
int answer;

void solve();
void tracking(int alpha, int taughtNum);
int getReadableWordsNum();
void separateStr();
void input();
void init();

int main(void) {
    init();
    input();
    solve();
    return 0;
}
void solve() {
    separateStr();
    if (K < 5)
        cout << 0 << "\n";
    else if (K == 26)
        cout << N << "\n";
    else {
        tracking(0, 5);
        cout << answer << "\n";
    }
}
//alpha : ��� ���ĺ� 
//taughtNum : ���ĺ��� ��� ���� 
void tracking(int alpha, int taughtNum) {
    if (taughtNum == K) {
        answer = max(answer, getReadableWordsNum());
        return;
    }
    for (int c = alpha; c < 26; ++c) {
        if (!taught[c]) {
            taught[c] = true;
            tracking(c, taughtNum + 1);
            taught[c] = false;
        }
    }
}
//���� �� �ִ� �ܾ��� ������ ��ȯ�Ѵ�.
int getReadableWordsNum() {
    int cnt = N;
    for (const auto& word : words) {
        for (const auto& c : word) {
            //����ġ�� ���� ���ĺ��� �ش� �ܾ �����ϸ�
            //���� �� �ִ� �ܾ �ϳ� ���̰� ���� �ܾ�� �Ѿ��.
            if (!taught[c - 'a']) {
                --cnt;
                break;
            }
        }
    }
    return cnt;
}
//���̻�� ���λ� ���� 
void separateStr() {
    for (int i = 0; i < int(words.size()); ++i) {
        string& word = words[i];
        word = string(word.begin() + 4, word.end());
        for (int i = 0; i < 4; ++i)
            word.pop_back();
    }
}
void input() {
    cin >> N >> K;
    words.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> words[i];
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    answer = -1;
    taught = vector<bool>(26, false); //���ĺ� ���� ��ŭ �ʱ�ȭ
    //a, n, t, i, c�� �ʼ� �湮 ǥ�� 
    taught['a' - 'a'] = true;
    taught['n' - 'a'] = true;
    taught['t' - 'a'] = true;
    taught['i' - 'a'] = true;
    taught['c' - 'a'] = true;
}