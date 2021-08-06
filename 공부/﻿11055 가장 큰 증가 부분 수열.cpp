#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1000] = {};
	int dp[1000] = {};	// dp[i] = A[i]를 포함하는 수열 중 가장 합이 큰 것

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) {
		dp[i] = A[i];
		for (int j = 0; j <= i; j++) {
			if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + A[i]);
		}
	}

	sort(dp, dp + N);

	printf("%d", dp[N - 1]);
}