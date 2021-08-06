#include <cstdio>

int main() {
	int T, n;
	int dp[12] = { 0,1,2,4 };
	
	scanf("%d", &T);

	for (int i = 4; i <= 11; i++) dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}