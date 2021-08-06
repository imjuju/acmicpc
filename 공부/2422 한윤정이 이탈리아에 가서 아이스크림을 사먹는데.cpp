#include <cstdio>

int main() {
	int N, M;
	int ans = 0;
	bool mix[201][201] = {};	// 섞어먹으면 안 되는 조합이면 true
	
	scanf("%d %d", &N, &M);

	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		mix[a][b] = mix[b][a] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				// 섞어먹으면 안 되는 조합이 하나라도 있으면
				if (mix[i][j] || mix[i][k] || mix[j][k]) continue;
				ans++;
			}
		}
	}

	printf("%d", ans);
}