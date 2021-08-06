#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

int main() {
	cin >> S;
	cin >> T;

	while (true) {
		if (S.size() == T.size()) {
			if (S == T) cout << 1;
			else cout << 0;
			return 0;
		}

		// 문자열의 끝이 A이면 A를 삭제한다
		if (T.back() == 'A') {
			T.pop_back();
		}
		// 문자열의 끝이 B이면 B를 삭제하고 문자열을 뒤집는다
		else if (T.back() == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
}