/*
방법 1 : 문자열 전체를 뒤집어서 원본 문자열과 같은지 비교 한다. 
방법 2 : isPalindrome 함수 : 문자열의 왼쪽끝, 오른쪽 끝 부터 비교하며 팰린드롬 유무를 확인한다. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPalindrome(string str);
int main(void) {
    int input;
    string inputStr, reverseStr;
    string answer;
    while (true) {
        cin >> input;
        if (input == 0) break;
        inputStr = to_string(input);
        reverseStr.resize(inputStr.size());
        reverse_copy(inputStr.begin(), inputStr.end(), reverseStr.begin());
        answer = inputStr == reverseStr ? "yes" : "no";
        cout << answer << "\n";
    }
    return 0;
}

bool isPalindrome(string str) {
    int leftPtr, rightPtr;

    leftPtr = 0, rightPtr = str.size() - 1;
    while (leftPtr < rightPtr) {
        if (str[leftPtr] == str[rightPtr]) {
            leftPtr++;
            rightPtr--;
        }
        else
            return false;
    }
    return true;
}