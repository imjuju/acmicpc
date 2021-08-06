#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int N; // 단어의 개수
char word[10][10];
int alpha[26];

bool desc(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", word[i]);
		
		int len = strlen(word[i]);
		int num = 1;
		for (int j = len - 1; j >= 0; j--) {
			alpha[word[i][j] - 'A'] += num;
			num *= 10;
		}
	}

	// 내림차순 정렬
	sort(alpha, alpha + 26, desc);
	//reverse(alpha, alpha + 26);
	
	for (int i = 9; i >= 0; i--) alpha[9 - i] *= i;
	
	int sum = 0;
	for (int i = 0; i <= 9; i++) sum += alpha[i];
	printf("%d", sum);
}