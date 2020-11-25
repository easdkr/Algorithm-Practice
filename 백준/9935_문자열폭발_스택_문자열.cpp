/*
스택 문제 분류인데 stl 스택을 사용하면 시간초과가 나는 문제 
[아이디어]
스택에 원본 문자열의 문자들을 하나씩 추가하다가 
폭발 문자열의 가장 끝 문자를 발견하면 
스택의 top부터 폭발 문자열의 길이만큼의 문자들을 검사하여 
폭발 문자열과 같은 경우 스택에서 제외시킨다. 
[주의점]
스택을 사용하면 폭발 문자열 비교시에 
폭발 문자열의 길이를 m, 원본 문자열을 n이라고 할 때, 
비교에 m번 만약 폭발 문자열이 아닐 시, 다시 집어넣는데 m번 수행
O(m*m*n)이 되어 m이 최대 36, n이 최대 100만이라 시간 초과가 난다 
[해결책]
stl 스택을 사용하지말고 배열을 선언해 인덱스로 접근하고 
폭발 문자열 검사 후 폭발 문자열이 아닌 경우에는 인덱스를 앞으로 당겨서 
덮어씌우는 방식을 사용한다.(다시 집어넣는 연산이 필요X) 

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
    vector<char> charStk; //스택 역할을 하는 char 배열 
    charStk.resize(1000001);
    int explosionSize = explosionStr.size(); //폭발 문자열의 길이
    char lastExplosionChar = explosionStr.back();//폭발 문자열의 마지막 문자 
    int stkIdx = 0; //스택 인덱스 
    for (const auto& c : originStr) {
        charStk[stkIdx++] = c; //스택에 집어넣는다
        //폭발문자열의 마지막 문자를 발견한 경우 (현재까지 읽은 문자가 폭발문자열보다 길어야함)
        if (c == lastExplosionChar && charStk.size() >= explosionSize) {
            int exIdx = explosionSize - 1; //폭발문자열의 뒤에서 부터 비교
            bool explosiveFind = true; //폭발문자열을 찾았을 경우의 flag 
            //스택의 뒤에서부터 폭발문자열의 길이만큼 비교한다. 
            for (int i = stkIdx-1; i >= stkIdx - explosionSize; --i) {
                if (explosionStr[exIdx] != charStk[i]) {
                    explosiveFind = false;
                    break;
                }
                exIdx--;
            }
            //만약 폭발문자열을 찾았다면 인덱스를 
            //폭발문자열 길이만큼 앞으로 옮긴다. 
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