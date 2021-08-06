// �� ���� �� ���� SCV�� ������ �� �ִ�
// ��, �� ���� ���ݿ��� ���� SCV�� ������ ������ ���� ����

// ù ��°�� ���ݹ޴� SCV�� ü�� 9�� �Ҵ´�
// �� ��°�� ���ݹ޴� SCV�� ü�� 3�� �Ҵ´�
// �� ��°�� ���ݹ޴� SCV�� ü�� 1�� �Ҵ´�

// SCV�� ü���� 0���ϰ� �Ǹ� ��� �ı���

// ��� SCV�� �ı��ϱ� ���� �����ؾ� �ϴ� Ƚ���� �ּڰ�

// 12 -> 12 - 3 = 9
// 10 -> 10 - 9 = 1
// 4  -> 4  - 1 = 3

// dp[12][10][4] = dp[9][1][3] + 1;
// dp[9][1][3] = dp[0][0][0] + 1;

#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int SVC[3];
int dp[61][61][61];

int func(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0) return 0;
	if (dp[a][b][c] != 0) return dp[a][b][c];

	int temp = 999;
	int na, nb, nc;
	na = (a - 9 < 0 ? 0 : a - 9);
	nb = (b - 3 < 0 ? 0 : b - 3);
	nc = (c - 1 < 0 ? 0 : c - 1);
	temp = min(temp, func(na, nb, nc) + 1);

	na = (a - 9 < 0 ? 0 : a - 9);
	nb = (b - 1 < 0 ? 0 : b - 1);
	nc = (c - 3 < 0 ? 0 : c - 3);
	temp = min(temp, func(na, nb, nc) + 1);

	na = (a - 3 < 0 ? 0 : a - 3);
	nb = (b - 1 < 0 ? 0 : b - 1);
	nc = (c - 9 < 0 ? 0 : c - 9);
	temp = min(temp, func(na, nb, nc) + 1);

	na = (a - 3 < 0 ? 0 : a - 3);
	nb = (b - 9 < 0 ? 0 : b - 9);
	nc = (c - 1 < 0 ? 0 : c - 1);
	temp = min(temp, func(na, nb, nc) + 1);

	na = (a - 1 < 0 ? 0 : a - 1);
	nb = (b - 3 < 0 ? 0 : b - 3);
	nc = (c - 9 < 0 ? 0 : c - 9);
	temp = min(temp, func(na, nb, nc) + 1);

	na = (a - 1 < 0 ? 0 : a - 1);
	nb = (b - 9 < 0 ? 0 : b - 9);
	nc = (c - 3 < 0 ? 0 : c - 3);
	temp = min(temp, func(na, nb, nc) + 1);

	dp[a][b][c] = temp;
	return temp;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &SVC[i]);
	printf("%d", func(SVC[0], SVC[1], SVC[2]));
}
