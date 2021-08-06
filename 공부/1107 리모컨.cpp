// �Ϻ� ���� ��ư�� ���峲

// ä�� 0���� -�� ���� ��� ä���� ������ ����
// ���� ���� �ִ� ä���� 100��

// � ��ư�� ���峵���� �־����� ��
// ä�� N���� �̵��ϱ� ���ؼ� ��ư�� �ּ� �� �� ������ �ϴ���

#include <cstdio>
#include <algorithm>
using namespace std;

int N;	// �̵��Ϸ��� �ϴ� ä��
int M;	// ���峭 ��ư�� ����
bool tf[10] = { 1,1,1,1,1,1,1,1,1,1 };	// tf[i] = ��ư i�� ���峵���� false

// 200�� �Է�
int possible(int idx) {
	if (idx == 100) return 0;
	if (idx == 0) return(tf[0] ? 1 : -1);

	int cnt = 0;	// ��ư�� �������ϴ� Ƚ��
	while (idx > 0) {
		if (!tf[idx % 10]) return -1;
		idx /= 10;
		cnt++;
	}

	return cnt;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	while (M--) {
		int temp;
		scanf("%d", &temp);
		tf[temp] = false;
	}

	if (N == 100) {
		printf("0");
		return 0;
	}

	int ans = abs(N - 100);
	int i = 0;
	while (i <= abs(N - 100)) {
		int left = N - i;
		int right = N + i;
		int cnt;	// ��ư�� �������ϴ� Ƚ��
					// ��ư �������� �̵� �Ұ����� ä���̸� -1
		
		if (left >= 0) cnt = possible(left);
		if (cnt == -1) cnt = possible(right);
		if (cnt != -1) {
			ans = min(ans, i + cnt);
			break;
		}
		i++;
	}

	printf("%d", ans);
}