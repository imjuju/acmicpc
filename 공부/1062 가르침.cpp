/* 비트마스크 이용한 풀이 */

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
int ans = -1;
char word[50][20];
int alpha[50];	// i번째 단어에 사용한 알파벳을 비트마스크를 이용해 표현



// cnt = 지금까지 고른 알파벳 개수
// idx = 지금 고를 알파벳
// mask = 고른 알파벳을 표현하는 비트마스크
void func(int cnt, int idx, int learn) {
	// 다 골랐을 때
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
// 어떤 K개의 글자를 가르쳐야
// 학생이 읽을 수 있는 단어의 개수가 최대가 되는지

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
int ans;
bool alpha[50][26];	// alpha[i][j] = i번째 단어에 j번째 알파벳이 쓰였는지
char word[50][20];
bool learn[26] = { 1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 };


// cnt = 지금까지 고른 알파벳 개수
void func(int cnt, int start) {
	if (cnt >= K) {
		int sum = 0;	// 배운 알파벳으로 읽을 수 있는 단어의 수

		for (int i = 0; i < N; i++) {
			bool tf = true;	// 읽을 수 없는 단어면 false로
			for (int j = 0; j < 26; j++) {
				// j번째 알파벳이 쓰였는데 배운적 없을 때
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
		// 고른 적 없는 알파벳일 때
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