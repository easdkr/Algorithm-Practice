/*
1. 왼쪽 괄호가 나올 때마다 스택에 넣습니다.

i) 여기서 핵심은 temp = 1로 선언하여 소괄호일 때는 2를 곱해주고 중괄호일 때는 3을 곱해주는 점입니다.

ii) 처음에 접근했을 때는 안에 내용물이 있을 때와 없을 때를 구분했다가 코드만 길어지고 실수를 하여 WA가 여러번 발생했습니다.

2. 시간 단축을 위해 불가능한 조합이 나올 경우 미리 반복문에서 탈출합니다.

i) 마지막에 impossible 혹은 스택이 비지 않았을 경우에 0을 출력하도록 했는데 간단한 예시를 들겠습니다.

(()()() 와 같은 경우 제가 정의한 불가능한 경우를 피해갑니다.

따라서, 반복문을 다 돌고도 스택이 비지 않았을 경우에도 불가능하다고 판단해야합니다.

3. 오른쪽 괄호가 나올 때마다 스택에서 뺍니다.

i) 바로 전 인덱스에 있던 괄호가 맞는 쌍일 경우에만 결과에 더해줍니다.

-> 결국 괄호쌍 내에 내용물이 있냐 없냐는 중요치 않았던 것입니다.(직접 종이에 해보시면 이유를 알 수 있을 것입니다.)

ii) 소괄호일 경우 temp에서 2를 나누어주고 중괄호일 경우 temp에서 3을 나누어줍니다.
*/
#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

string input;
stack<char> s;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	cin >> input;

	long long result = 0;
	int temp = 1;
	bool impossible = false;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (input[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (input[i] == ')') {
			if (input[i - 1] == '(')
				result += temp;

			s.pop();
			temp /= 2;
		}

		else if (input[i] == ']') {
			if (input[i - 1] == '[')
				result += temp;

			s.pop();
			temp /= 3;
		}
		//불가능한 경우
		else if (input[i] == ')' && (s.empty() || s.top() != '(')) {
			impossible = true;
			break;
		}
		else if (input[i] == ']' && (s.empty() || s.top() != '[')) {
			impossible = true;
			break;
		}
	}
	if (impossible || !s.empty())
		cout << 0 << "\n";
	else
		cout << result << "\n";

	return 0;

}