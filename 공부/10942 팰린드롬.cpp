#include <cstdio>

int N, M;
int S, E;
int arr[2001] = {};
int dp[2001][2001] = {};

int search(int left, int right) {
	if (left == right) {
		dp[left][right] = 1;
		return dp[left][right];
	}
	else if (left + 1 == right) {
		dp[left][right] = (arr[left] == arr[right] ? 1 : 0);
		return dp[left][right];
	}
	else if (dp[left][right] == -1) {
		dp[left][right] = (arr[left] == arr[right] && search(left + 1, right - 1) == 1 ? 1 : 0);
		return dp[left][right];
	}
	else return dp[left][right];

}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dp[i][j] = -1;
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d", &S, &E);
		printf("%d\n", search(S, E));
	}
}