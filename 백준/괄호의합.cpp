#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std; 
int solution(string str);
bool calc(stack<string>& stk, string wrong_pair, string correct_pair, int typeValue);
int main() {
	string input;
	cin >> input;
	cout << solution(input);
	return 0;
}

int solution(string str) {
	int len = str.size();
	stack<string> stk;
	int ret = 0;
	bool check = true;
	for (int i = 0; i < len; ++i) {
		string element = string(1, str[i]);
		//여는 괄호인 경우 스택에 push
		if (element == "(" || element == "[")
			stk.push(element);
		//닫는 괄호에 대한 처리 
		else {
			//스택이 비어있는 경우 예외사례
			if (stk.empty())
				return 0;
			if (element == ")") {
				//스택의 top이 짝이 맞는 '(' 일 경우 
				//스택에서 '('를 pop 한 후 2를 스택에 push
				if (stk.top() == "(") {
					stk.pop();
					stk.push(to_string(2));
				}
				//스택의 top이 '('가 아닌 경우
				//예외사례이거나 숫자가 들어있는 경우 계산을 해야한다. 
				else {
					check = calc(stk, "[", "(", 2);
				}
			}
			// element == ')'과 마찬가지로 처리한다. 
			else if (element == "]") {
				if (stk.top() == "[") {
					stk.pop();
					stk.push(to_string(3));
				}
				else {
					check = calc(stk, "(", "[", 3);
				}
			}
			//예외 처리 
			if (check == false) 
				return 0;
		}
	}
	//마지막에 스택에는 자연수만 남아있게된다. 
	while (!stk.empty()) {
		string t = stk.top(); stk.pop();
		if (t == "(" || t == ")" || t == "[" || t == "]")
			return 0;
		else
			ret += atoi(t.c_str());
	}
	return ret;
}

bool calc(stack<string>& stk, string wrong_pair, string correct_pair, int typeValue) {
	bool ret = true;
	int calcVal = 0;
	while (!stk.empty()) {
		//cout << "?";
		string t = stk.top(); stk.pop();
		if (t == wrong_pair) {
			ret = false;
			break;
		}
		else if (t == correct_pair) {
			calcVal *= typeValue;
			stk.push(to_string(calcVal));
			break;
		}
		else 
			calcVal += atoi(t.c_str());
	}
	return ret;
}