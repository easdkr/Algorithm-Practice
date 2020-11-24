#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main(void) {
    string input; //�Է� ���ڿ� 
    stack<char> s;//��ȣ�� ���� ����
    char preChar = ' ';//���� ���� ����
    
    int answer = 0;
    cin >> input;
    //currChar ���� ����
    for (const auto& currChar : input) {
        if (currChar == '(')
            s.push('(');
        else {
            //�������� ��� 
            if (preChar == '(') {
                //( ���ڸ� �ϳ� pop�ϰ�(�������� (�����̹Ƿ�)
                //������ ũ�⸦ ���Ѵ� (�߸� ������ ���� == ������ ũ��) 
                s.pop();
                answer += s.size();
            }
            //������� ������ ���
            else {
                //����Ⱑ �������ϱ� �����ϳ� pop
                s.pop();
                answer += 1;
            }
        }
        preChar = currChar;
    }
    cout << answer << "\n";
    return 0;
}