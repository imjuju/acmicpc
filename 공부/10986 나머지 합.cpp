#include <cstdio>

int N, M, S;
long long ans;
int cnt[1010] = { 1 };	// cnt[i] = M으로 나눈 나머지 값이 i인 S의 개수

int main() {
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		S = (S + temp) % M;
		cnt[S]++;
	}

	for (int i = 0; i < M; i++) {
		if (cnt[i] >= 2)
			ans += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2;
	}
		
	printf("%lld", ans);
}