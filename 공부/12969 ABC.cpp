#include <cstdio>

bool tf;
int N, K;
bool dp[40][40][40][500];	// dp[길이][A개수][B개수][(i,j) 쌍의 개수]
char ans[40];

bool func(int idx, int a, int b, int p) {
	if (idx == N) {
		if (p == K) return true;
		else return false;
	}
	
	// 이전에 방문한 적 있으면 탐색하지 않는다
	if (dp[idx][a][b][p]) return false;
	// 방문 체크
	dp[idx][a][b][p] = true;

	ans[idx] = 'A';
	if (func(idx + 1, a + 1, b, p)) return true;

	ans[idx] = 'B';
	if (func(idx + 1, a, b + 1, p + a)) return true;

	ans[idx] = 'C';
	if (func(idx + 1, a, b, p + a + b)) return true;

	return false;
}
int main() {
	scanf("%d %d", &N, &K);

	
	if (func(0, 0, 0, 0)) {
		for (int i = 0; i < N; i++) printf("%c", ans[i]);
	}
	else printf("-1");
} 