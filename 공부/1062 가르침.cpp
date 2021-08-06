/* ��Ʈ����ũ �̿��� Ǯ�� */

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
int ans = -1;
char word[50][20];
int alpha[50];	// i��° �ܾ ����� ���ĺ��� ��Ʈ����ũ�� �̿��� ǥ��



// cnt = ���ݱ��� �� ���ĺ� ����
// idx = ���� �� ���ĺ�
// mask = �� ���ĺ��� ǥ���ϴ� ��Ʈ����ũ
void func(int cnt, int idx, int learn) {
	// �� ����� ��
	if (cnt >= K) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if ((alpha[i] & ((1 << 26) - 1 - learn)) == 0) temp++;
		}

		ans = max(ans, temp);
		return;
	}
	
	if (idx >= 26) return;

	if (idx == 'a' - 'a' || idx == 'n' - 'a' || idx == 't' - 'a' || idx == 'i' - 'a' || idx == 'c' - 'a') {
		func(cnt, idx + 1, learn);
	}
	else {
		func(cnt, idx + 1, learn);
		func(cnt + 1, idx + 1, learn | (1 << idx));
	}

}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%s", word[i]);

	if (K < 5) {
		printf("0");
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int len = strlen(word[i]);
		for (int j = 0; j < len; j++)
			alpha[i] |= (1 << (word[i][j] - 'a'));
	}

	int learn = 0;
	learn |= (1 << ('a' - 'a'));
	learn |= (1 << ('n' - 'a'));
	learn |= (1 << ('t' - 'a'));
	learn |= (1 << ('i' - 'a'));
	learn |= (1 << ('c' - 'a'));

	func(5, 0, learn);

	printf("%d", ans);
}

/*
// � K���� ���ڸ� �����ľ�
// �л��� ���� �� �ִ� �ܾ��� ������ �ִ밡 �Ǵ���

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
int ans;
bool alpha[50][26];	// alpha[i][j] = i��° �ܾ j��° ���ĺ��� ��������
char word[50][20];
bool learn[26] = { 1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 };


// cnt = ���ݱ��� �� ���ĺ� ����
void func(int cnt, int start) {
	if (cnt >= K) {
		int sum = 0;	// ��� ���ĺ����� ���� �� �ִ� �ܾ��� ��

		for (int i = 0; i < N; i++) {
			bool tf = true;	// ���� �� ���� �ܾ�� false��
			for (int j = 0; j < 26; j++) {
				// j��° ���ĺ��� �����µ� ����� ���� ��
				if (alpha[i][j] && !learn[j]) {
					tf = false;
					break;
				}
			}
			if (tf) sum++;
		}

		if (ans < sum) ans = sum;
		return;
	}

	for (int i = start; i < 26; i++) {
		// �� �� ���� ���ĺ��� ��
		if (!learn[i]) {
			learn[i] = true;
			func(cnt + 1, i + 1);
			learn[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%s", word[i]);

	if (K < 5) {
		printf("0");
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int len = strlen(word[i]);
		for (int j = 0; j < len; j++)
			alpha[i][word[i][j] - 'a'] = true;
	}

	func(5, 1);
	printf("%d", ans);
}
*/