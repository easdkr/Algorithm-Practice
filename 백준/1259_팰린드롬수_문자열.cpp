/*
��� 1 : ���ڿ� ��ü�� ����� ���� ���ڿ��� ������ �� �Ѵ�. 
��� 2 : isPalindrome �Լ� : ���ڿ��� ���ʳ�, ������ �� ���� ���ϸ� �Ӹ���� ������ Ȯ���Ѵ�. 
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