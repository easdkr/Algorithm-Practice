/*
[음수의 경우]
음수 2개는 곱해서 더하는게 항상 더 큰 결과 
음수가 1개의 경우, 0이 있다면 0이랑 곱해서 더하는게 항상 더 큰 결과 

[양수의 경우]
1보다 큰 양수의 경우, 곱해서 더하는게 항상 더 큰 결과 
1의 경우는 그냥 더하는게 항상 더 큰 결과 
양수가 1개만 남으면, 그냥 더함 

양수는 max heap에 저장하고, 음수는 min heap에 저장 
0의 개수는 상관 없고 존재 유무만 체크하면 된다 
1은 개수체크! 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>, less<int>> positive; //양수 max heap 저장
priority_queue<int, vector<int>, greater<int>> negative; //음수 min heap 저장 
bool zeroFlag = false; //0 존재하는가? 
int oneNum = 0; // 1의 개수 
int main(void) {
    cin >> N;
    int inputNum;
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        cin >> inputNum;
        //1보다 큰 수만 max heap 저장 
        if (inputNum > 1)
            positive.push(inputNum);
        //0보다 작은 수만 min heap 저장 
        else if (inputNum < 0)
            negative.push(inputNum);
        //1의 개수 저장 
        else if (inputNum == 1)
            oneNum++;
        //0이 존재한다면 flag 변경 
        else
            zeroFlag = true;
    }
    //1은 모두 곱셈하지 않고 그냥 더함
    answer += oneNum;
    //양수 2개씩 빼서 곱하고 저장 
    while (positive.size() >= 2) {
        int a = positive.top();
        positive.pop();
        int b = positive.top();
        positive.pop();
        answer += (a * b);
    }
    //남은 수가 존재한다면 그냥 더함 
    if (!positive.empty()) {
        answer += positive.top();
        positive.pop();
    }
    //음수 2개씩 빼서 곱하고 저장 
    while (negative.size() >= 2) {
        int a = negative.top();
        negative.pop();
        int b = negative.top();
        negative.pop();
        answer += (a * b);
    }
    //남은 음수가 존재할 때, 
    //0이 존재한다면 0을 더함(= 아무것도 안함)
    //0이 존재하지 않으면 그 수를 더함 
    if (!negative.empty()) {
        if (!zeroFlag) {
            answer += negative.top();
            negative.pop();
        }
    }
    cout << answer;
    return 0;
}