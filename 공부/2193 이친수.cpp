// 0���� �������� �ʴ´�
// 1�� �� �� �������� ��Ÿ���� �ʴ´�

#include <cstdio>

int main() {
	int N;
	long long dp[91][2] = {};	// dp[i][j] = ���̰� i�� j�� ������ ��ģ���� ����
	
	scanf("%d", &N);
	
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld", dp[N][0] + dp[N][1]);
}