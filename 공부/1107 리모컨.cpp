// 일부 숫자 버튼이 고장남

// 채널 0에서 -를 누른 경우 채널이 변하지 않음
// 지금 보고 있는 채널은 100번

// 어떤 버튼이 고장났는지 주어졌을 때
// 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야 하는지

#include <cstdio>
#include <algorithm>
using namespace std;

int N;	// 이동하려고 하는 채널
int M;	// 고장난 버튼의 개수
bool tf[10] = { 1,1,1,1,1,1,1,1,1,1 };	// tf[i] = 버튼 i가 고장났으면 false

// 200을 입력
int possible(int idx) {
	if (idx == 100) return 0;
	if (idx == 0) return(tf[0] ? 1 : -1);

	int cnt = 0;	// 버튼을 눌러야하는 횟수
	while (idx > 0) {
		if (!tf[idx % 10]) return -1;
		idx /= 10;
		cnt++;
	}

	return cnt;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	while (M--) {
		int temp;
		scanf("%d", &temp);
		tf[temp] = false;
	}

	if (N == 100) {
		printf("0");
		return 0;
	}

	int ans = abs(N - 100);
	int i = 0;
	while (i <= abs(N - 100)) {
		int left = N - i;
		int right = N + i;
		int cnt;	// 버튼을 눌러야하는 횟수
					// 버튼 고장으로 이동 불가능한 채널이면 -1
		
		if (left >= 0) cnt = possible(left);
		if (cnt == -1) cnt = possible(right);
		if (cnt != -1) {
			ans = min(ans, i + cnt);
			break;
		}
		i++;
	}

	printf("%d", ans);
}