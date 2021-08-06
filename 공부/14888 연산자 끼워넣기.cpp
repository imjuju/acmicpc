#include <cstdio>

int main() {
	int N, K;
	int dp[201][201] = {};	// dp[i][j] = j개를 더해서 합이 i이 되는 경우의 수
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) dp[i][1] = 1;

	for (int i = 2; i <= K; i++) 
		for (int j = 0; j <= N; j++) 
			for (int k = 0; k <= j; k++)
				dp[j][i] = (dp[j][i] + dp[k][i - 1]) % 1000000000;

	printf("%d", dp[N][K]);
}