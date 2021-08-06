#include <cstdio>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int T, K;
int a[501];	// ������ ũ��
int sum[501];		// sum[i] = a[1]���� a[i]������ ��
int dp[501][501];	// dp[i][j] = a[i]���� a[j]���� ������ ��ĥ �� �ּ� ���
					// = dp[i][mid] + dp[mid + 1][j]�� �ּڰ� + a[i]���� a[j]������ ��

int search(int left, int right) {
	if (left == right) {
		dp[left][right] = 0;
		return 0;
	}

	if (dp[left][right] != -1) return dp[left][right];

	dp[left][right] = INT_MAX;
	for (int mid = left; mid < right; mid++) {
		dp[left][right] = min(dp[left][right], search(left, mid) + search(mid + 1, right) + sum[right] - sum[left - 1]);
	}
	return dp[left][right];
}

int main() {
	scanf("%d", &T);

	while (T--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &K);
		for (int i = 1; i <= K; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		printf("%d\n", search(1, K));
	}
}