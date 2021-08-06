// 0�� 0������ ���� ��������
// ���� �����¿�� �̵��� �� ����
// ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����

// ���� �ִ��� �� ĭ�� ���� �� �ִ��� ���ض�

#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;	// ���� ����
int ans;
char map[20][20];
bool alpha[26];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void search(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

		int na = map[ny][nx];	// next alpha
		
		// ������ �� ���� ���ĺ��̸�
		if (!alpha[na - 'A']) {
			alpha[na - 'A'] = true;
			search(ny, nx);
			alpha[na - 'A'] = false;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (alpha[i]) cnt++;
	ans = max(ans, cnt);
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			scanf(" %c", &map[i][j]);
	

	alpha[map[0][0] - 'A'] = true;
	search(0, 0);

	printf("%d", ans);
}