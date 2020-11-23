/*
[������ ���]
���� 2���� ���ؼ� ���ϴ°� �׻� �� ū ��� 
������ 1���� ���, 0�� �ִٸ� 0�̶� ���ؼ� ���ϴ°� �׻� �� ū ��� 

[����� ���]
1���� ū ����� ���, ���ؼ� ���ϴ°� �׻� �� ū ��� 
1�� ���� �׳� ���ϴ°� �׻� �� ū ��� 
����� 1���� ������, �׳� ���� 

����� max heap�� �����ϰ�, ������ min heap�� ���� 
0�� ������ ��� ���� ���� ������ üũ�ϸ� �ȴ� 
1�� ����üũ! 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>, less<int>> positive; //��� max heap ����
priority_queue<int, vector<int>, greater<int>> negative; //���� min heap ���� 
bool zeroFlag = false; //0 �����ϴ°�? 
int oneNum = 0; // 1�� ���� 
int main(void) {
    cin >> N;
    int inputNum;
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        cin >> inputNum;
        //1���� ū ���� max heap ���� 
        if (inputNum > 1)
            positive.push(inputNum);
        //0���� ���� ���� min heap ���� 
        else if (inputNum < 0)
            negative.push(inputNum);
        //1�� ���� ���� 
        else if (inputNum == 1)
            oneNum++;
        //0�� �����Ѵٸ� flag ���� 
        else
            zeroFlag = true;
    }
    //1�� ��� �������� �ʰ� �׳� ����
    answer += oneNum;
    //��� 2���� ���� ���ϰ� ���� 
    while (positive.size() >= 2) {
        int a = positive.top();
        positive.pop();
        int b = positive.top();
        positive.pop();
        answer += (a * b);
    }
    //���� ���� �����Ѵٸ� �׳� ���� 
    if (!positive.empty()) {
        answer += positive.top();
        positive.pop();
    }
    //���� 2���� ���� ���ϰ� ���� 
    while (negative.size() >= 2) {
        int a = negative.top();
        negative.pop();
        int b = negative.top();
        negative.pop();
        answer += (a * b);
    }
    //���� ������ ������ ��, 
    //0�� �����Ѵٸ� 0�� ����(= �ƹ��͵� ����)
    //0�� �������� ������ �� ���� ���� 
    if (!negative.empty()) {
        if (!zeroFlag) {
            answer += negative.top();
            negative.pop();
        }
    }
    cout << answer;
    return 0;
}