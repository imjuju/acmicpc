// ���ڿ��� ���̴� N
// 'A', 'B'�θ� �̷���� ����
// 0 �� i < j < N �̸鼭
// s[i] == 'A' && s[j] == 'B'�� �����ϴ� (i, j) ���� K���� ����

#include <cstdio>
#include <string.h>
using namespace std;

int N, K;
char ans[60];
bool dp[60][60][1500];

bool func(int idx, int a, int p) {
	if (idx == N) {
		if (p == K) return true;
		else return false;
	}
	
	if (dp[idx][a][p]) return false;
	dp[idx][a][p] = true;

	ans[idx] = 'A';
	if (func(idx + 1, a + 1, p)) return true;

	ans[idx] = 'B';
	if (func(idx + 1, a, p + a)) return true;

	return false;
}

int main() {
	scanf("%d %d", &N, &K);

	if (func(0, 0, 0)) {
		for (int i = 0; i < N; i++) printf("%c", ans[i]);
	}
	else printf("-1");
}
