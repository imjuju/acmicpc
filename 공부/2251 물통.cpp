#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A, B, C;
bool visit[201][201][201];	// visit[A][B][C]
bool ans[201];

void search(int a, int b, int c) {
	if (a == 0) ans[c] = true;
	
	if (visit[a][b][c]) return;
	visit[a][b][c] = true;

	if (a > 0) {
		// A에서 B
		if (b + a > B) search(b + a - B, B, c);
		else search(0, b + a, c);

		// A에서 C
		if (c + a > C) search(c + a - C, b, C);
		else search(0, b, c + a);
	}
	if (b > 0) {
		// B에서 A
		if (a + b > A) search(A, a + b - A, c);
		else search(a + b, 0, c);
		
		// B에서 C
		if (c + b > C) search(a, c + b - C, C);
		else search(a, 0, c + b);
	}
	if (c > 0) {
		// C에서 A
		if (a + c > A) search(A, b, a + c - A);
		else search(a + c, b, 0);

		// C에서 B
		if (b + c > B) search(a, B, b + c - B);
		else search(a, b + c, 0);
	}
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	search(0, 0, C);
	for (int i = 0; i <= C; i++)
		if (ans[i]) printf("%d ", i);
}