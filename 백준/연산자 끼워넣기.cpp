#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector<int> operand;
vector<int> oper; //operator
vector<int> result_vector;
//now_result : 현재까지 계산값
//oper_num : 연산자 번호 
//_operand : 연산할 수 
int calc(int now_result, int oper_num, int _operand) {
	if (oper_num == 0)
		return now_result += _operand;
	else if (oper_num == 1)
		return now_result -= _operand;
	else if (oper_num == 2)
		return now_result *= _operand;
	else
		return now_result /= _operand;
}
// this_turn : 이번에 연산할 수의 차례
// oper : 남아있는 연산자의 배열
// result : 현재까지 계산한 값 
void solution(int this_turn, vector<int>& oper, int result) {
	if (this_turn == N) {
		result_vector.push_back(result);
		return;
	}
	for (int i = 0; i < oper.size(); ++i) {
		if (oper[i] > 0) {
			int next_result = calc(result, i, operand[this_turn]);
			oper[i]--;
			solution(this_turn + 1, oper, next_result);
			oper[i]++;
		}
	}
}
int main(void){
	cin >> N;
	operand = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> operand[i];
	oper = vector<int>(4);
	for (int i = 0; i < 4; ++i)
		cin >> oper[i];

	solution(1, oper, operand[0]);

	if (result_vector.size() == 1)
		cout << result_vector[0] << "\n" << result_vector[0];
	else {
		sort(result_vector.begin(), result_vector.end());
		cout << result_vector[result_vector.size() - 1] << "\n" << result_vector[0];
	}
	return 0;
}