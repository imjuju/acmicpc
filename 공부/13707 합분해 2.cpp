#include <cstdio>

int main() {
	int N, K;
	int dp[5001] = {}; // dp[i][j] = i를 j개로 만드는 경우
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) dp[i] = 1;
	
	for (int i = 2; i <= K; i++)
		for (int j = 1; j <= N; j++)
			dp[j] = (dp[j - 1] + dp[j]) % 1000000000;
			
	printf("%d", dp[N]);
}