#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main(void) {
    string input; //입력 문자열 
    stack<char> s;//괄호를 담을 스택
    char preChar = ' ';//이전 문자 저장
    
    int answer = 0;
    cin >> input;
    //currChar 현재 문자
    for (const auto& currChar : input) {
        if (currChar == '(')
            s.push('(');
        else {
            //레이저의 경우 
            if (preChar == '(') {
                //( 문자를 하나 pop하고(레이저의 (문자이므로)
                //스택의 크기를 더한다 (잘린 나무의 개수 == 스택의 크기) 
                s.pop();
                answer += s.size();
            }
            //막대기의 끝점의 경우
            else {
                //막대기가 끝났으니까 문자하나 pop
                s.pop();
                answer += 1;
            }
        }
        preChar = currChar;
    }
    cout << answer << "\n";
    return 0;
}