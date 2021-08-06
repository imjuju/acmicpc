// 하루에 한 명만 출근한다

// A = 매일 출근 가능
// B = 출근한 다음날은 쉬어야
// C = 출근한 다음날, 다다음날은 쉬어야

// 올바른 출근 기록 아무거나 출력

#include <iostream>
using namespace std;

bool dp[60][60][60][3][3];	// dp[a개수][b개수][c개수][전날 일한 사람][전전날 일한 사람]
char ans[60];

// p1, p2: A = 0, B = 1, C = 2
bool func(int idx, int a, int b, int c, int p1, int p2) {
	if (a == 0 && b == 0 && c == 0) {
		return true;
	}

	// 이전에 방문한 적 있으면 탐색하지 않는다
	if (dp[a][b][c][p1][p2]) return false;
	// 방문 체크
	dp[a][b][c][p1][p2] = true;

	// 사용할 수 있는 A가 있을 때
	if (a > 0) {
		ans[idx] = 'A';
		if (func(idx + 1, a - 1, b, c, 0, p1)) return true;
	}

	// 사용할 수 있는 B가 있고
	// 전날 B가 출근하지 않았을 때
	if (b > 0 && p1 != 1) {
		ans[idx] = 'B';
		if (func(idx + 1, a, b - 1, c, 1, p1)) return true;
	}

	// 사용할 수 있는 C가 있고
	// 전날, 전전날 C가 출근하지 않았을 때
	if (c > 0 && p1 != 2 && p2 != 2) {
		ans[idx] = 'C';
		if (func(idx + 1, a, b, c - 1, 2, p1)) return true;
	}

	return false;
}
int main() {
	int a = 0, b = 0, c = 0;
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') a++;
		else if (S[i] == 'B') b++;
		else if (S[i] == 'C') c++;
	}

	if (func(0, a, b, c, -1, -1)) {
		for (int i = 0; i < S.size(); i++) cout<< ans[i];
	}
	else cout << "-1";
}