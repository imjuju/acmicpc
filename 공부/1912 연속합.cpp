#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int a[100001];
	int dp[100001] = { -9999 };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) dp[i] = max(a[i], a[i] + dp[i - 1]);
	
	sort(dp + 1, dp + n + 1);

	printf("%d", dp[n]);
}