#include <cstdio>

int N, dist;
long long dp[100][100];	// dp[i][j] = (0,0)���� (i,j)�� �� �� �ִ� ����� ��

int main() {
	scanf("%d", &N);

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &dist);
			if (i == N - 1 && j == N - 1) break;
			if (i + dist < N) dp[i + dist][j] += dp[i][j];
			if (j + dist < N) dp[i][j + dist] += dp[i][j];
		}
	}

	printf("%lld", dp[N - 1][N - 1]);
}