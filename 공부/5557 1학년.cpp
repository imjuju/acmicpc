#include <cstdio>

int N;
int a[100];
long long dp[100][21];	// dp[i][j] = i��° ������ ����ؼ� j�� ����� ����� ��

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	dp[0][a[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (0 <= j + a[i] && j + a[i] <= 20) dp[i][j + a[i]] += dp[i - 1][j];
				if (0 <= j - a[i] && j - a[i] <= 20) dp[i][j - a[i]] += dp[i - 1][j];
			}
		}
	}

	printf("%lld", dp[N - 2][a[N - 1]]);
}