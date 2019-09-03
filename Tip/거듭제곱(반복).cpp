#include <iostream>
using namespace std;

//2^
long long pow(long long x, long long y) {
    long long ret = 1;
    while(y != 0){
        if(y % 2 == 1)
            ret = ret * x;
        x = x * x;
        y = y / 2;
    }
	return ret;
}