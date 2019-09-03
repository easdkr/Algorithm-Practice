#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
int plusCalc(char* expression);

int solve(string input);
int main(void) {
	string input;
	cin >> input;
	cout << solve(input) << "\n";
	return 0;
}
int solve(string input) {
	int ret = 0;
	//계산식을 -를  기준으로 자른다.
	vector<char*> cal;
	const char* delim = "-";
	char* expression = new char[input.size() + 1];
	strcpy(expression, input.c_str());
	char* token = strtok(expression, delim);
	cal.push_back(token);
	while (true) {
		token = strtok(NULL, delim);
		if (token) cal.push_back(token);
		else break;
	}

	//잘려진 식을 계산한다. 
	ret = plusCalc(cal[0]);
	//첫 수가 음수인 경우 처리
	if (expression[0] == '-') ret *= -1;
	for (int i = 1; i < cal.size(); ++i)
		ret -= plusCalc(cal[i]);
	return ret;
}
//표현식의 덧셈 연산을 계산한다. 
int plusCalc(char* expression) {
	int ret = 0;
	const char* delim = "+";
	char* token = strtok(expression, delim);
	ret = stoi(token);
	while(true) {
		token = strtok(NULL, delim);
		if (token) ret += stoi(token);
		else break;
	}
	return ret;
}
