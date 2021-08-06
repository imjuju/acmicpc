#include <cstdio>

int main() {
	int N;
	int dp[100001] = { 0,1 };
	
	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		
		dp[i] = i;

		for (int j = 1; j <= i / 2; j++) {
			if (j * j == i) {
				dp[i] = 1;
				break;
			}
			else if (j * j > i) break;
		}

		if (dp[i] == 1) continue;

		for (int j = 1; j <= i / 2; j++) 
			if (dp[i] > dp[j] + dp[i - j]) dp[i] = dp[j] + dp[i - j];
		
	}

	printf("%d ", dp[N]);
}