#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
DP문제라고하지만 알고리즘은 완전탐색에 가깝다. 
몇개의 연속된 N (ex N== 2일때 ,3개가 연속되면 222 )을 이번 연산에 참여시킬지 결정한 후
재귀함수로 사칙연산을 적용하여 만들 수 있는 모든 숫자를 탐색하며
목표인 number를 만들 수 있는 최소 N의 갯수를 찾아간다. 
*/

const int max_int = 987654321;
int expression(int cnt, int curr, int number, int N);
int solution(int N, int number) {
	int answer = 0;
	answer = expression(0, 0, number, N);
	return answer;
}
//현재까지 만든 수가 curr, 현재 사용한 개수 : cnt 일때 
//number를 만드는 최수 연산의 횟수를 반환하라 
int expression(int cnt, int curr, int number, int N) {
	int ret = max_int;
    //기저 사례
	if (cnt > 8) return -1;
    //타겟 number와 같으면 종료 
	if (curr == number) return cnt;
    //연산되는 수를 몇개나 연속된 N으로 연산할 것인지 확정하고 
    //재귀함수로 연산을 실행한다.  
    int oper = 0; //연산되는 수
    int temp; // 결과값을 확인 
    for(int i = 0; i <= 7; ++i){
        oper += (i == 0 ? N : (i)*10*N);
        //덧셈 연산 
        if ((temp = expression(cnt + i + 1, curr + oper, number, N)) != -1)
            ret = min(ret, temp);
        //뺄셈 연산 
        if ((temp = expression(cnt + i + 1, curr - oper, number, N)) != -1)
            ret = min(ret, temp);
        //곱셈 연산 
        if ((temp = expression(cnt + i + 1, curr * oper, number, N)) != -1)
            ret = min(ret, temp);
        //나눗셈 연산 
        if ((temp = expression(cnt + i + 1, curr / oper, number, N)) != -1)
            ret = min(ret, temp);
    }
	if (ret == max_int) return -1;
    return ret;
}

int main(void){
    int N = 5;
    int number =12;
    cout << solution(N, number);
    return 0;
}
