/*
���� ���� �з��ε� stl ������ ����ϸ� �ð��ʰ��� ���� ���� 
[���̵��]
���ÿ� ���� ���ڿ��� ���ڵ��� �ϳ��� �߰��ϴٰ� 
���� ���ڿ��� ���� �� ���ڸ� �߰��ϸ� 
������ top���� ���� ���ڿ��� ���̸�ŭ�� ���ڵ��� �˻��Ͽ� 
���� ���ڿ��� ���� ��� ���ÿ��� ���ܽ�Ų��. 
[������]
������ ����ϸ� ���� ���ڿ� �񱳽ÿ� 
���� ���ڿ��� ���̸� m, ���� ���ڿ��� n�̶�� �� ��, 
�񱳿� m�� ���� ���� ���ڿ��� �ƴ� ��, �ٽ� ����ִµ� m�� ����
O(m*m*n)�� �Ǿ� m�� �ִ� 36, n�� �ִ� 100���̶� �ð� �ʰ��� ���� 
[�ذ�å]
stl ������ ����������� �迭�� ������ �ε����� �����ϰ� 
���� ���ڿ� �˻� �� ���� ���ڿ��� �ƴ� ��쿡�� �ε����� ������ ��ܼ� 
������ ����� ����Ѵ�.(�ٽ� ����ִ� ������ �ʿ�X) 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void solve();
void input();
void init();
string originStr;
string explosionStr;
int main(void) {
    init();
    input();
    solve();
    return 0;
}
void solve() {
    string answer;
    vector<char> charStk; //���� ������ �ϴ� char �迭 
    charStk.resize(1000001);
    int explosionSize = explosionStr.size(); //���� ���ڿ��� ����
    char lastExplosionChar = explosionStr.back();//���� ���ڿ��� ������ ���� 
    int stkIdx = 0; //���� �ε��� 
    for (const auto& c : originStr) {
        charStk[stkIdx++] = c; //���ÿ� ����ִ´�
        //���߹��ڿ��� ������ ���ڸ� �߰��� ��� (������� ���� ���ڰ� ���߹��ڿ����� ������)
        if (c == lastExplosionChar && charStk.size() >= explosionSize) {
            int exIdx = explosionSize - 1; //���߹��ڿ��� �ڿ��� ���� ��
            bool explosiveFind = true; //���߹��ڿ��� ã���� ����� flag 
            //������ �ڿ������� ���߹��ڿ��� ���̸�ŭ ���Ѵ�. 
            for (int i = stkIdx-1; i >= stkIdx - explosionSize; --i) {
                if (explosionStr[exIdx] != charStk[i]) {
                    explosiveFind = false;
                    break;
                }
                exIdx--;
            }
            //���� ���߹��ڿ��� ã�Ҵٸ� �ε����� 
            //���߹��ڿ� ���̸�ŭ ������ �ű��. 
            if (explosiveFind)
                stkIdx -= explosionSize;
        }
    }
    if (stkIdx == 0)
        answer = "FRULA";
    else {
        for (int i = 0; i < stkIdx; ++i)
            answer.push_back(charStk[i]);
    }
    cout << answer;
}
void input() {
    cin >> originStr;
    cin >> explosionStr;
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}