#include <iostream>
using namespace std;
int H, M;
int main(void){
	cin >> H >> M;
	M -= 45;
	if (M < 0) {
		if (H == 0)
			H = 23;
		else 
			--H;
		M += 60;
	}
	cout << H << " " << M;
	return 0;
}