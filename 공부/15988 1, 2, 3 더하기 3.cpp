#include <cstdio>

int main() {
	int T, n;
	int dp[1000001] = { 0,1,2,4 };

	scanf("%d", &T);

	for (int i = 4; i <= 1000000; i++)
		dp[i] = ((dp[i - 3] + dp[i - 2]) % 1000000009 + dp[i - 1]) % 1000000009;

	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}