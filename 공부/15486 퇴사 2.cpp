// N + 1ÀÏ¿¡ Åð»ç

#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int T[1500001];
int P[1500001];
int dp[1500002];

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) scanf("%d %d", &T[i], &P[i]);

	for (int i = 1; i <= N; i++) {
		dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	printf("%d", dp[N + 1]);

}