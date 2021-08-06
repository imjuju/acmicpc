#include <cstdio>
#include <stdlib.h> // exit �Լ� ���� ����
#include <vector>
using namespace std;

bool c1[9][10];	// ��	c1[i][j] i���� j�� ������ true
bool c2[9][10];	// ��	
bool c3[9][10];	// �簢
int a[9][9];
vector<pair<int, int> > empty_idx;	// ����ִ� ĭ�� idx�� ����

void search(int idx) {
	if (idx == empty_idx.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d ", a[i][j]);
			printf("\n");
		}
		exit(0);
	}

	int y = empty_idx[idx].first;
	int x = empty_idx[idx].second;

	for (int i = 1; i <= 9; i++) {
		// ����� �� �ִ� ���̸�
		if (!c1[y][i] && !c2[x][i] && !c3[y / 3 * 3 + x / 3][i]) {
			a[y][x] = i;
			c1[y][i] = c2[x][i] = c3[y / 3 * 3 + x / 3][i] = true;
			search(idx + 1);
			a[y][x] = 0;
			c1[y][i] = c2[x][i] = c3[y / 3 * 3 + x / 3][i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			c1[i][a[i][j]] = true;
			c2[j][a[i][j]] = true;
			c3[i / 3 * 3 + j / 3][a[i][j]] = true;
			if (a[i][j] == 0) empty_idx.push_back({ i,j });
		}
	}

	search(0);
}