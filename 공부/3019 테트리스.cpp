#include <cstdio>
#include <string>
using namespace std;

int C, P;
int ans;
int map[100];

int cal(int a, string s) {
	// 블록이 칸을 넘어갈 때
	if (a + s.size() > C) return 0;

	int len = s.size();

	for (int i = 0; i <= len - 2; i++) {
		if ((s[i + 1] - '0') - (s[i] - '0') != map[a + i + 1] - map[a + i]) return 0;
	}

	return 1;
}

int main() {
	scanf("%d %d", &C, &P);
	for (int i = 0; i < C; i++) scanf("%d", &map[i]);

	for (int i = 0; i < C; i++) {
		if (P == 1) ans += cal(i, "0") + cal(i, "0000");
		else if (P == 2) ans += cal(i, "00");
		else if (P == 3) ans += cal(i, "001") + cal(i, "10");
		else if (P == 4) ans += cal(i, "100") + cal(i, "01");
		else if (P == 5) ans += cal(i, "000") + cal(i, "01") + cal(i, "101") + cal(i, "10");
		else if (P == 6) ans += cal(i, "000") + cal(i, "00") + cal(i, "011") + cal(i, "20");
		else if (P == 7) ans += cal(i, "000") + cal(i, "00") + cal(i, "110") + cal(i, "02");
	}

	printf("%d", ans);
}