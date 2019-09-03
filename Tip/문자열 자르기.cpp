#include <iostream>
#include <string>
#include <vector>
//strtok는 방금전에 분리한 문자열의 분리지점 바로 다음 주소값을 기억한다. 
//첫번째 인자로 str의 주소값이 들어오면 거기서 부터 분리를 시작하고
//NULL이 들어오면 이전에 기억된 주소부터 분리를 시도한다. 
using namespace std;
//input의 입력 문자열을 histo 배열에 저장한다. 
void stringToArray(string input, vector<long long>& histo) {
	//공백을 기준으로 문자열을 자른다. 
	const char* delim = " ";
	//string 을 char 배열형태로 파싱 
	char* str = new char[input.size() + 1];
	//strcpy_s(str, input.size()+1, input.c_str());
	std::strcpy(str, input.c_str());
	//첫번째 토큰을 잘라낸다. 
	//char* token = strtok_s(NULL, delim, &str);
	char* token = strtok(str, delim);
	histo.push_back(stoll(token));
	//잘라낼 문자열이 없을 때까지 반복한다.
	while (true) {
		//자르기
		//token = strtok_s(NULL, delim, &str);
		token = strtok(NULL, delim);
		if (token) histo.push_back(stoll(token));
		else break;
	}
}