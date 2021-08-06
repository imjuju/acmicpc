#include <cstdio>

int N, S, M;
int V[101];
bool dp[101][1001];	// dp[i][j] = i번째 곡을 j볼륨으로 연주할 수 있으면 true

int main() {
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &V[i]);	
	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (0 <= j + V[i] && j + V[i] <= M) dp[i][j + V[i]] = true;
				if (0 <= j - V[i] && j - V[i] <= M) dp[i][j - V[i]] = true;
			}
		}
	}

	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			printf("%d", i);
			return 0;
		}
	}

	printf("-1");
}