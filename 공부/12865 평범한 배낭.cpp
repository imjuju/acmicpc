#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, K, ans = -1;
	int w[101];
	int v[101];
	int dp[100001] = {};

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &w[i], &v[i]);

	for (int i = 1; i <= N; i++) 
		for (int j = K; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			

	for (int i = 0; i <= K; i++) ans = max(ans, dp[i]);

	printf("%d", ans);
}


/*

// dp[i][j] = i��° ���Ǳ��� ����߰� �賶�� ���� ������ ���԰� j�� �� ��ġ �ִ�
// dp[i-1][j] = i��° ������ ���濡 ���� �ʾ��� ��
// dp[i-1][j-w[i]] + v[i] = i���� ������ ���濡 �־��� ��

// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])

#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int N, K, ans = -1;
	int w[101];
	int v[101];
	int dp[101][1001] = {};	 

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) 
		scanf("%d %d", &w[i], &v[i]);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	for (int i = 0; i <= K; i++) ans = max(ans, dp[N][i]);

	printf("%d", ans);
	
}
*/