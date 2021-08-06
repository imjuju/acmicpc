// 0으로 시작하지 않는다
// 1이 두 번 연속으로 나타나지 않는다

#include <cstdio>

int main() {
	int N;
	long long dp[91][2] = {};	// dp[i][j] = 길이가 i인 j로 끝나는 이친수의 개수
	
	scanf("%d", &N);
	
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld", dp[N][0] + dp[N][1]);
}