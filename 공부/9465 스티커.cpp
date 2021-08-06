// ��ƼĿ�� �� �� ����
// �����¿��� ��ƼĿ�� ����� �� ���� �ȴ�

// �� ��ƼĿ�� ������ �ű��
// ������ ���� �ִ밡 �ǰ� ��ƼĿ�� ������� �Ѵ�

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, n;
	int sticker[2][100001] = {};
	int dp[2][100001] = {};	// dp[i][j] = sticker[i][j]�� �� �� �ִ밡 �Ǵ� ����

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &sticker[0][i]);
		for (int i = 1; i <= n; i++) scanf("%d", &sticker[1][i]);
		
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = sticker[0][i] + max(dp[0][i - 2], max(dp[1][i - 2], dp[1][i - 1]));
			dp[1][i] = sticker[1][i] + max(dp[0][i - 2], max(dp[1][i - 2], dp[0][i - 1]));
		}

		printf("%d\n", max(max(dp[0][n - 1], dp[1][n - 1]), max(dp[0][n], dp[1][n])));
	}

}