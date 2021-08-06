// ���� ���� 1��ĭ ���� ������

// 0 ������ ĭ (�̵� �Ұ�)
// 1 ������ ĭ

// i -> i + 1
// i -> i - 1
// ��i -> ���� i + k or ���� i- > �� i + k

// N�� ĭ���� ū ĭ���� �̵��ϸ� clear

// 1�ʿ� �� ĭ�� �����
// ������ ���� �����̰� ĭ�� �����

// ���� ���� �������� ������
// ��������

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, k;
int map[2][100001];
bool visit[2][100001];
int dist[2][100001];

void BFS() {
	queue<pair<int, int> > q;	// {left = 0 right = 1, idx}
	q.push({ 0,1 });
	visit[0][1] = true;
	dist[0][1] = 1;

	while (!q.empty()) {
		int state = q.front().first;
		int idx = q.front().second;
		q.pop();

		int nstate, nidx;
		// ������ �̵�
		nstate = state; nidx = idx + 1;
		if (nidx > N) {
			printf("1");
			return;
		}
		else if (nidx == N && map[nstate][nidx] == 1) {
			printf("1");
			return;
		}
		if (dist[state][idx] < nidx && map[nstate][nidx] == 1 && !visit[nstate][nidx]) {
			visit[nstate][nidx] = true;
			dist[nstate][nidx] = dist[state][idx] + 1;
			q.push({ nstate,nidx });
		}

		// �ڷ� �̵�
		nstate = state; nidx = idx - 1;
		if (dist[state][idx] < nidx && map[nstate][nidx] == 1 && !visit[nstate][nidx]) {
			visit[nstate][nidx] = true;
			dist[nstate][nidx] = dist[state][idx] + 1;
			q.push({ nstate,nidx });
		}

		// ����
		nstate = 1 - state; nidx = idx + k;
		if (nidx > N) {
			printf("1");
			return;
		}
		else if (nidx == N && map[nstate][nidx] == 1) {
			printf("1");
			return;
		}
		if (dist[state][idx] < nidx && map[nstate][nidx] == 1 && !visit[nstate][nidx]) {
			visit[nstate][nidx] = true;
			dist[nstate][nidx] = dist[state][idx] + 1;
			q.push({ nstate,nidx });
		}
	}

	printf("0");
}

int main() {
	scanf("%d %d", &N, &k);
	
	for (int i = 1; i <= N; i++) scanf("%1d", &map[0][i]);
	for (int i = 1; i <= N; i++) scanf("%1d", &map[1][i]);

	BFS();
}