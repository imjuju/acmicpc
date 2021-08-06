#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;	// ���� ����
int ans = -1;
int a[4][4];	// ���ڸ� ���� �迭

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &a[i][j]);
	
	for (int s = 0; s < (1 << (N * M)); s++) {
		int sum = 0;

		// ���� ���
		for (int y = 0; y < N; y++) {
			int temp = 0;	// y�࿡ �ִ� ������ ��
			for (int x = 0; x < M; x++) {
				int k = y * M + x;
				if ((s & (1 << k)) == 0) {
					temp = temp * 10 + a[y][x];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}

		for (int x = 0; x < M; x++) {
			int temp = 0;	// x���� �ִ� ������ ��
			for (int y = 0; y < N; y++) {
				int k = y * M + x;
				if ((s & (1 << k)) != 0) {
					temp = temp * 10 + a[y][x];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}

		ans = max(ans, sum);
	}

	printf("%d", ans);
}
/*
// ���� ���������� �Ʒ���
// ���� ���ʺ��� ����������

#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;	// ���� ����
int ans = -1;
int a[4][4];	// ���ڸ� ���� �迭
int b[4][4];	// �������� �������� ���� �迭


int calc() {
	int sum = 0;
	bool visit[4][4] = {};
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!visit[y][x]) {
				// ����
				if (b[y][x] == 0) {
					int temp = 0;
					int i = 0;
					while (x + i < M) {
						if (b[y][x + i] == 1) break;
						temp = temp * 10 + a[y][x + i];
						visit[y][x + i] = true;
						i++;
					}
					sum += temp;
				}
				// ����
				else {
					int temp = 0;
					int i = 0;
					while (y + i < N) {
						if (b[y + i][x] == 0) break;
						temp = temp * 10 + a[y + i][x];
						visit[y + i][x] = true;
						i++;
					}
					sum += temp;
				}
			}
		}
	}

	return sum;
}

void func(int idx) {
	if (idx == N * M) {
		ans = max(ans, calc());
		return;
	}

	int y = idx / M;
	int x = idx % M;

	b[y][x] = 0;
	func(idx + 1);
	
	b[y][x] = 1;
	func(idx + 1);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &a[i][j]);
	func(0);
	printf("%d", ans);
}
*/