// N개의 시험장
// i번 시험장의 응시자 수 = Ai명

// 총 감독관 = 한 시험장에서 감시할 수 있는 응시자 수 B명
// 부 감독관 = 한 시험장에서 감시할 수 있는 응시자 수 C명

// 각 시험장에 총 감독관은 오직 1명
// 부 감독관은 여러명 있어도 됨

// 응시생들을 모두 감시할 수 있는 최소 감독관 수

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