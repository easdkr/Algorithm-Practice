#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string A, B;
int main(void){
	cin >> A >> B;
	int ret = 987654321;
	//A의 문자열을 B의 문자열 0번 부터 비교.. 1번부터 비교.. 이런식으로 진행
	//가장 작은 차이를 가진게 문제의 답 
	//앞뒤로 붙이는 문자는 내맘이니까 ! 
	for (int i = 0; i <= B.size() - A.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < A.size(); ++j)
			if (B[i+j] != A[j])
				cnt++;
		ret = min(ret, cnt);
	}
	cout << ret;
	return 0;
}