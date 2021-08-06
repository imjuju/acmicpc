#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
	int n, k;
	int coin[100] = {};
	int dp[100001] = {};	// dp[i] = i원을 만드는 최소 동전 개수
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (dp[j - coin[i]] != -1) {
				if (dp[j] == -1) dp[j] = dp[j - coin[i]] + 1;
				else dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			}
		}
	}

	printf("%d", dp[k]);
}