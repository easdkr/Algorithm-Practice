/*
문자열 + 백트래킹 문제이다. 
K개 만큼 알파벳을 가르쳤다고 가정할때, 
주어진 N개의 단어 중 K개의 알파벳만으로 이루어진 단어의 개수를 구한다, 
이 때 단어의 개수를 최대화하는 K개의 조합을 찾아 최대 단어의 개수를 구해야한다. 

문제는 결국 
K개 알파벳들의 모든 조합을 찾고(back tracking)이용 
조합이 완성되면, 단어를 검사하여 해당 조합으로만 이루어진 단어 찾기이다. 

주의할 점)
a, n, t, i, c는 무조건 가르쳐야하는 알파벳이다.
 - K가 5 이하이면 배울 수 있는 단어가 없다 : 0 출력
K가 26이면 모든 단어를 배울 수 있다 : N 출력 
모든 단어에 접두사 anta, 접미사 tica는 고정이므로 
입력 문자열에서 제거해준다. 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N; //단어의 개수 
int K; //가르쳐야할 글자(알파벳)의 개수 
vector<bool> taught; //가르친 알파벳 체크
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
//alpha : 배운 알파벳 
//taughtNum : 알파벳을 배운 개수 
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
//읽을 수 있는 단어의 개수를 반환한다.
int getReadableWordsNum() {
    int cnt = N;
    for (const auto& word : words) {
        for (const auto& c : word) {
            //가르치지 않은 알파벳이 해당 단어에 존재하면
            //읽을 수 있는 단어를 하나 줄이고 다음 단어로 넘어간다.
            if (!taught[c - 'a']) {
                --cnt;
                break;
            }
        }
    }
    return cnt;
}
//접미사와 접두사 제거 
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
    taught = vector<bool>(26, false); //알파벳 개수 만큼 초기화
    //a, n, t, i, c는 필수 방문 표시 
    taught['a' - 'a'] = true;
    taught['n' - 'a'] = true;
    taught['t' - 'a'] = true;
    taught['i' - 'a'] = true;
    taught['c' - 'a'] = true;
}