#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	int T, n;
	int dp[10001] = {1};	// dp[i] = ���� i�� �Ǵ� ����� ��
	scanf("%d", &T);

	for (int i = 1; i <= 3; i++) 
		for (int j = 1; j <= 10000; j++)
			if (j - i >= 0) dp[j] += dp[j - i];
	
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}

/*
// ���� �̷�� ���� ���������� �ǵ��� 

#include <cstdio>

int main() { 
	int T, n;
	int dp[10001][4] = {};	// dp[i][j] = j�� ������ ���� i�� �Ǵ� ��
	scanf("%d", &T);

	dp[1][1] = 1;
	dp[2][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3]);
	}
}
*/