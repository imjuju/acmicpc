// N���� ������
// i�� �������� ������ �� = Ai��

// �� ������ = �� �����忡�� ������ �� �ִ� ������ �� B��
// �� ������ = �� �����忡�� ������ �� �ִ� ������ �� C��

// �� �����忡 �� �������� ���� 1��
// �� �������� ������ �־ ��

// ���û����� ��� ������ �� �ִ� �ּ� ������ ��

#include <cstdio>

int N; 
int A[1000000];
int B, C;

long long count(int idx) {
	if (A[idx] < B) return 1;

	return ((A[idx] - B) % C == 0 ? (A[idx] - B) / C + 1 : (A[idx] - B) / C + 2);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);

	long long ans = 0;
	for (int i = 0; i < N; i++) 
		ans += count(i);
	
	printf("%lld", ans);
}