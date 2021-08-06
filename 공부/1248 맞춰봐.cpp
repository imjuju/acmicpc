// ���̿� �� N���� ���
// ������ ��� N*(N+1)/2���� ������ ���� ���ߴ�
// �����̴� �̰� ��ķ� ǥ���ߴ�

// �����̰� �� ���� A���ϸ�
// A[i] = �����̰� i��° �� ��

// S[i][j] = A[i]���� A[j]���� ���� 0���� ũ�� +, 0�̸� 0, 0���� ������ -
// i < j



#include <cstdio>
#include <stdlib.h>

int N;
int arr[10][10];

int ans[10];

bool check(int num, int idx) {
	for (int i = 0; i <= idx; i++) {
		int sum = num;
		for (int j = i; j < idx; j++) sum += ans[j];

		if (arr[i][idx] == -1 && sum >= 0) return false;
		if (arr[i][idx] == 0 && sum != 0) return false;
		if (arr[i][idx] == 1 && sum <= 0) return false;
	}

	return true;
}


void func(int idx) {
	if (idx == N) {
		for (int i = 0; i < N; i++) printf("%d ", ans[i]);
		exit(0);
	}

	if (arr[idx][idx] == 0) {
		ans[idx] = 0;
		func(idx + 1);
	}

	else if (arr[idx][idx] == -1) {
		for (int i = -10; i < 0; i++) {
			if (check(i, idx)) {
				ans[idx] = i;
				func(idx + 1);
			}
		}
	}

	else if (arr[idx][idx] == 1) {
		for (int i = 1; i <= 10; i++) {
			if (check(i, idx)) {
				ans[idx] = i;
				func(idx + 1);
			}
		}
	}

	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			char temp;
			scanf(" %c", &temp);
			if (temp == '-') arr[i][j] = -1;
			else if (temp == '0') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	func(0);
}