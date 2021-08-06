// �Ϸ翡 �� �� ����Ѵ�

// A = ���� ��� ����
// B = ����� �������� �����
// C = ����� ������, �ٴ������� �����

// �ùٸ� ��� ��� �ƹ��ų� ���

#include <iostream>
using namespace std;

bool dp[60][60][60][3][3];	// dp[a����][b����][c����][���� ���� ���][������ ���� ���]
char ans[60];

// p1, p2: A = 0, B = 1, C = 2
bool func(int idx, int a, int b, int c, int p1, int p2) {
	if (a == 0 && b == 0 && c == 0) {
		return true;
	}

	// ������ �湮�� �� ������ Ž������ �ʴ´�
	if (dp[a][b][c][p1][p2]) return false;
	// �湮 üũ
	dp[a][b][c][p1][p2] = true;

	// ����� �� �ִ� A�� ���� ��
	if (a > 0) {
		ans[idx] = 'A';
		if (func(idx + 1, a - 1, b, c, 0, p1)) return true;
	}

	// ����� �� �ִ� B�� �ְ�
	// ���� B�� ������� �ʾ��� ��
	if (b > 0 && p1 != 1) {
		ans[idx] = 'B';
		if (func(idx + 1, a, b - 1, c, 1, p1)) return true;
	}

	// ����� �� �ִ� C�� �ְ�
	// ����, ������ C�� ������� �ʾ��� ��
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