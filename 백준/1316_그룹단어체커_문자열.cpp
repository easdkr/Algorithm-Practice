/*
visited에 각 문자가 등장했는지 체크한다.  
각 단어별로 모든 문자를 확인하면서 
직전 문자와 다른 문자인 경우 visited에서 확인하고 
이미 등장한 문자일 경우 해당 단어는 그룹 단어가 아니다. (탐색종료)
등장한적이 없으면 해당 문자를 visited에 체크해주고, 탐색을 계속한다. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;// 단어의 개수 
vector<string> words; //단어들을 저장

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
        //visited 초기화 
        visited = vector<bool>(26, false);
        //첫번째 문자를 visited 체크
        visited[word[0] - 'a'] = true;
        //1번부터 마지막 인덱스까지 탐색한다. 
        for (int i = 1; i < int(word.size()); ++i) {
            //이전 문자와 다른 문자가 등장한 경우 
            if (word[i] != word[i - 1]) {
                //이미 등장한 문자인 경우 
                if (visited[word[i] - 'a']) {
                    //그룹단어가 될수 없다.
                    --answer;
                    break;
                }
                //등장한 적이 없으면 visited에 체크
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