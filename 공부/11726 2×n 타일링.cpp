#include <cstdio>

int main() {
	int n;
	int dp[1001] = {};	// dp[i] = 2xi 크기의 직사각형을 채우는 방법의 수
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

	printf("%d", dp[n]);
}