#include <cstdio>

int main() {
	int N;
	int dp[1001][10] = {};	// dp[i][j] = j로 끝나는 길이가 i인 오르막 수
	
	scanf("%d", &N);

	for (int i = 0; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] += (dp[i - 1][k] % 10007);
	


	int sum = 0;
	for (int i = 0; i <= 9; i++) sum += (dp[N][i] % 10007);
	printf("%d", sum % 10007);
}