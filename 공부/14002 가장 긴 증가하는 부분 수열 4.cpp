#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int N;
	int A[1000] = {};
	int dp[1000] = {};	// dp[i] = A[i]를 포함하는 수열 중 가장 길이가 긴 것
	int from[1000] = {};
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		from[i] = -1;
		for (int j = 0; j <= i; j++) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				from[i] = j;
			}
		}
	}


	int max_idx, max_val = 0;
	stack<int> s;

	for (int i = 0; i < N; i++) {
		if (max_val < dp[i]) {
			max_val = dp[i];
			max_idx = i;
		}
	}

	while (max_idx != -1) {
		s.push(A[max_idx]);
		max_idx = from[max_idx];
	}
	
	printf("%d\n", max_val);
	
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
}