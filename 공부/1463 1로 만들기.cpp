#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int dp[1000001] = {};	// dp[i] i�� 1�� ����� �ּ� Ƚ��
	
	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
	}

	printf("%d", dp[N]);
}