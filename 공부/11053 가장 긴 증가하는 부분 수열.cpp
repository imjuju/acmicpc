#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1000] = {};
	int dp[1000] = {};	// dp[i] = A[i]�� �����ϴ� ���� �� ���� ���̰� �� ��

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	sort(dp, dp + N);
	
	printf("%d", dp[N - 1]);
}