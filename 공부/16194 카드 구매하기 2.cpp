#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int P[1001] = {};
	int dp[1001] = {};	// dp[i] = i장을 구매하기 위한 금액의 최솟값

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);

	for (int i = 1; i <= N; i++) {
		dp[i] = P[i];
		for (int j = 1; j <= i / 2; j++) dp[i] = min(dp[i], dp[i - j] + dp[j]);
	}

	printf("%d", dp[N]);
}