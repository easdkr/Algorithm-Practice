/*
visited�� �� ���ڰ� �����ߴ��� üũ�Ѵ�.  
�� �ܾ�� ��� ���ڸ� Ȯ���ϸ鼭 
���� ���ڿ� �ٸ� ������ ��� visited���� Ȯ���ϰ� 
�̹� ������ ������ ��� �ش� �ܾ�� �׷� �ܾ �ƴϴ�. (Ž������)
���������� ������ �ش� ���ڸ� visited�� üũ���ְ�, Ž���� ����Ѵ�. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;// �ܾ��� ���� 
vector<string> words; //�ܾ���� ����

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
    int answer = N;
    vector<bool> visited;
    for (const auto& word : words) {
        //visited �ʱ�ȭ 
        visited = vector<bool>(26, false);
        //ù��° ���ڸ� visited üũ
        visited[word[0] - 'a'] = true;
        //1������ ������ �ε������� Ž���Ѵ�. 
        for (int i = 1; i < int(word.size()); ++i) {
            //���� ���ڿ� �ٸ� ���ڰ� ������ ��� 
            if (word[i] != word[i - 1]) {
                //�̹� ������ ������ ��� 
                if (visited[word[i] - 'a']) {
                    //�׷�ܾ �ɼ� ����.
                    --answer;
                    break;
                }
                //������ ���� ������ visited�� üũ
                else
                    visited[word[i] - 'a'] = true;
            }
        }
        visited.clear();
    }
    cout << answer;
}
void input() {
    cin >> N;
    words.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> words[i];
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}