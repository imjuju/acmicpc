// dp[3][1][1][1] = dp[2][0][1][1] + dp[2][1][0][1] + dp[2][1][1][0]
// dp[2][0][1][1] = dp[1][0][0][1] + dp[1][0][1][0]
// dp[1][0][0][1] = dp[0][0][0][0]


// dp[3][3][1][1] = dp[2][2][1][1] + dp[2][3][0][1] + dp[2][3][1][0]
// dp[2][2][1][1] = dp[1][1][1][1] + dp[1][2][0][1] + 

#include <cstdio>

int dp[51][51][51][51];


int func(int s, int d, int k, int h) {
	if (s == 0 && d == 0 && k == 0 && h == 0) return 1;
	if (s < d || s < k || s < h) return 0;
	if (s > d + k + h) return 0;
	if (s - 1 < 0) return 0;
	if (dp[s][d][k][h] != 0) return dp[s][d][k][h];

	int temp = 0;
	if (d - 1 >= 0 && k - 1 >= 0 && h - 1 >= 0) temp = (temp + func(s - 1, d - 1, k - 1, h - 1)) % 1000000007;
	if (d - 1 >= 0 && k - 1 >= 0) temp = (temp + func(s - 1, d - 1, k - 1, h)) % 1000000007;
	if (d - 1 >= 0 && h - 1 >= 0) temp = (temp + func(s - 1, d - 1, k, h - 1)) % 1000000007;
	if (k - 1 >= 0 && h - 1 >= 0) temp = (temp + func(s - 1, d, k - 1, h - 1)) % 1000000007;
	if (d - 1 >= 0) temp = (temp + func(s - 1, d - 1, k, h)) % 1000000007;
	if (k - 1 >= 0) temp = (temp + func(s - 1, d, k - 1, h)) % 1000000007;
	if (h - 1 >= 0) temp = (temp + func(s - 1, d, k, h - 1)) % 1000000007;
	dp[s][d][k][h] = temp;
	return temp;
}


int main() {
	int S, D, K, H;
	scanf("%d %d %d %d", &S, &D, &K, &H);
	printf("%d", func(S, D, K, H));
}