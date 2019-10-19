#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size(); ++i) {
		string base = phone_book[i];
		for (int j = i + 1; j < phone_book.size(); ++j) {
			string target = phone_book[j];
			if (target.find(base, 0) != string::npos)
				return false;
		}
	}
	return answer;
}

int main(void) {
	vector<string> phone_book = { "119", "97674223", "1195524421" };
	cout << solution(phone_book);
	return 0;
}