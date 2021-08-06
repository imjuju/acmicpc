#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1000];
	int dp1[1000] = {};	// dp1[i] = 0 ~ i까지의 A[i]를 포함하는 수열 중 가장 길이가 긴 것
	int dp2[1000] = {};	// dp2[i] = i ~ N - 1까지의 A[i]를 포함하는 수열 중 가장 길이가 긴 것

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) {
		dp1[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (A[j] < A[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = N - 1; j >= i; j--) {
			if (A[j] < A[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	for (int i = 0; i < N; i++) dp1[i] = dp1[i] + dp2[i] - 1;

	sort(dp1, dp1 + N);

	printf("%d", dp1[N - 1]);
}