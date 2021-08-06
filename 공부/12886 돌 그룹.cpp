// 1) 크기가 같지 않은 두 그룹을 고른다
// 2) 작은 쪽 = X, 큰 쪽 = Y
// 3) X -> X + X
//	  Y -> Y - X

#include <cstdio>

int ans;
bool visit[1501][1501];

void func(int A, int B, int C) {
	if (visit[A][B]) return;
	visit[A][B] = true;

	if (A == B && B == C && A == C) {
		ans++;
		return;
	}
	if (A != B) {
		if (A > B) func(A - B, B + B, C);
		else func(A + A, B - A, C);

	}
	if (A != C) {
		if (A > C) func(A - C, B, C + C);
		else func(A + A, B, C - A);
	}
	if (B != C) {
		if (B > C) func(A, B - C, C + C);
		else func(A, B + B, C - B);
	}
}

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	func(A, B, C);

	if (ans == 0) printf("0");
	else printf("1");
}