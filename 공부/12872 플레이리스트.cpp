// ��� �뷡�� �÷��̸���Ʈ�� �߰��ؾ�
// ���� �뷡�� �߰��Ϸ���,
// �÷��̸���Ʈ���� �� �뷡 ���� ��� M���� ���� �־����

#include <cstdio>
#include <string.h>	// memset
using namespace std;

const long long MOD = 1000000007;
int N, M, P;
long long dp[101][101][101];	// dp[�÷��̸���Ʈ ����][�̹� �߰��� �뷡][�߰��� �� ���� �뷡]

// p = ���� �÷��̸���Ʈ�� ����, x = �̹� �߰��� �뷡, y = �߰��� �� ���� �뷡
long long func(int idx, int x, int y) {
	// �÷��̸���Ʈ�� �ϼ����� ��
	if (idx == P) {
		// ��� �뷡�� �÷��̸���Ʈ�� �߰������� - ���� 1 ��ȯ
		if (y == 0) return 1;
		// �÷��̸���Ʈ�� �߰����� ���� �뷡�� ������ - �Ұ��� 0 ��ȯ
		else return 0;
	}

	if (dp[idx][x][y] != -1) return dp[idx][x][y];
	

	long long temp = 0;

	
	// �̹� �߰��� �뷡�� �� �߰��ϴ� ���
	if (x - M > 0) {
		temp = (temp + func(idx + 1, x, y) * (x - M)) % MOD;
	}

	// �߰��� �� ���� �뷡�� �߰��ϴ� ���
	if (y > 0) {
		temp = (temp + func(idx + 1, x + 1, y - 1) * y) % MOD;
	}

	dp[idx][x][y] = temp;

	return dp[idx][x][y];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &P);

	printf("%lld", func(0, 0, N));
}