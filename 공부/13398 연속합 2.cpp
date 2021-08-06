#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	int n;
	int a[100000];
	int dp[100000][2];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	dp[0][0] = a[0];
	dp[1][0] = max(a[1], dp[0][0] + a[1]);
	dp[1][1] = max(a[0], a[1]);
	
	for (int i = 2; i < n; i++) {
		dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
	}

	
	int max_val = max(dp[0][0], max(dp[1][0], dp[1][1]));
	
	for (int i = 2; i < n; i++) max_val = max(max_val, max(dp[i][0], dp[i][1]));

	printf("%d", max_val);
}