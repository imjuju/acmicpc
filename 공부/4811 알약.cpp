#include <cstdio>

long long dp[31][31];	// 약통에 약이 F개, 반 조각이 H개 있을 때 약을 먹는 방법의 수

long long func(int whole, int half) {
	if (whole == 0 && half == 0) return 1;
	if (dp[whole][half] > 0) return dp[whole][half];
	
	long long temp = 0;
	if (whole - 1 >= 0) temp += func(whole - 1, half + 1);
	if (half - 1 >= 0) temp += func(whole, half - 1);
	dp[whole][half] = temp;

	return temp;
}

int main() {
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == 0) return 0;
		printf("%lld\n", func(N, 0));
	}
}

