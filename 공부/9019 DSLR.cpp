// n = d1 d2 d3 d4

// 명령어 D
// n * 2 % 10,000

// 명령어 S
// n - 1 (단, n = 0이면 9999를 저장)

// 명령어 L
// 왼쪽 회전
// d2 d3 d4 d1

// 명령어 R
// 오른쪽 회전
// d4 d1 d2 d3

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

char c[4] = { 'D','S','L','R' };
bool visit[10000] = {};
int from[10000] = {};
char how[10000] = {};

void print(int A, int B) {
	if (from[B] != A) print(A, from[B]);
	cout << how[B];
}
int calc(int n, int idx) {
	// D
	if (idx == 0) return  n * 2 % 10000;

	// S
	else if (idx == 1) return (n == 0 ? 9999 : n - 1);

	// L
	else if (idx == 2) return (n % 1000) * 10 + n / 1000;

	// R
	else return (n % 10) * 1000 + n / 10;
}

void BFS(int A, int B) {
	memset(visit, false, sizeof(visit));
	queue<int> q;
	
	visit[A] = true;
	q.push(A);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == B) {
			print(A, B);
			cout << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int next = calc(now, i);
			if (!visit[next]) {
				visit[next] = true;
				from[next] = now;
				how[next] = c[i];
				q.push(next);
			}
		}

	}
}

int main() {
	int T;

	cin >> T;

	while (T--) {
		int A, B;
		cin >> A >> B;
		BFS(A, B);
	}

}