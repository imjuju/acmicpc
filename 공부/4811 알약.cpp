#include <cstdio>

long long dp[31][31];	// ���뿡 ���� F��, �� ������ H�� ���� �� ���� �Դ� ����� ��

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

