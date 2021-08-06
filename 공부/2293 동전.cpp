#include <cstdio>

int main() {
	int n, k;
	int coin[100] = {};
	int dp[100001] = {1};	// dp[i] = i원을 만드는 경우의 수
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	for (int i = 0; i < n; i++) 
		for (int j = coin[i]; j <= k; j++) 
			dp[j] += dp[j - coin[i]];
	
	printf("%d", dp[k]);
}