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

		// ���ڿ��� ���� A�̸� A�� �����Ѵ�
		if (T.back() == 'A') {
			T.pop_back();
		}
		// ���ڿ��� ���� B�̸� B�� �����ϰ� ���ڿ��� �����´�
		else if (T.back() == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
}