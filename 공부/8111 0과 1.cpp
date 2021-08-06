#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

bool visit[20001];
int from[20001];
int how[20001];

void print(int idx) {
	if (from[idx] != -1) print(from[idx]);
	printf("%d", how[idx]);
}


int main() {
	int T, N;
	scanf("%d", &T);

	while (T--) {
		memset(visit, false, sizeof(visit));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));

		scanf("%d", &N);

		queue<int> q;
		q.push(1 % N);
		visit[1 % N] = true;
		from[1 % N] = -1;
		how[1 % N] = 1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == 0) {
				print(0);
				printf("\n");
			}

			for (int i = 0; i <= 1; i++) {
				int next = (now * 10 + i) % N;
				if (!visit[next]) {
					visit[next] = true;
					from[next] = now;
					how[next] = i;
					q.push(next);
				}
			}
		}
	}
}