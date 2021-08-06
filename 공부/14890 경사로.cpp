#include <cstdio>
#include <vector>
using namespace std;

int N, L, ans;
int map[100][100];

vector<int> v;
vector<bool> c;

bool check() {
	for (int i = 1; i < N; i++) {
		if (v[i - 1] != v[i]) {
			// �ϰ� ���� = v[i]�� ���� ĭ
			if (v[i - 1] - v[i] == 1) {
				for (int j = 0; j < L; j++) {
					// ���θ� ���ٰ� ������ ����� ���
					if (i + j >= N) return false;

					// ���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���ӵ��� ���� ���
					if (v[i] != v[i + j]) return false;

					// ���θ� ���� ���� �� ���θ� ���� ���
					if (c[i + j]) return false;

					c[i + j] = true;
				}
			}

			// ��� ���� = v[i-1]�� ���� ĭ
			else if (v[i - 1] - v[i] == -1) {
				for (int j = 0; j < L; j++) {
					// ���θ� ���ٰ� ������ ����� ���
					if (i - 1 - j < 0) return false;

					// ���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���ӵ��� ���� ���
					if (v[i - 1] != v[i - 1 - j]) return false;

					// ���θ� ���� ���� �� ���θ� ���� ���
					if (c[i - 1 - j]) return false;

					c[i - 1 - j] = true;
				}
			}

			// ���� ĭ�� ���� ĭ�� ���� ���̰� 1�� �ƴ� ���
			else return false;
		}
	}

	return true;
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// �� �˻�
	for (int i = 0; i < N; i++) {
		v.clear();
		c.clear();
		for (int j = 0; j < N; j++) v.push_back(map[i][j]);
		for (int j = 0; j < N; j++) c.push_back(false);
		bool tf = check();
		if (tf) ans++;
	}

	// �� �˻�
	for (int i = 0; i < N; i++) {
		v.clear();
		c.clear();
		for (int j = 0; j < N; j++) v.push_back(map[j][i]);
		for (int j = 0; j < N; j++) c.push_back(false);
		bool tf = check();
		if (tf) ans++;
	}

	printf("%d", ans);
}