// 두 팀의 인원수는 같지 않아도 됨
// 한 명 이상이어야

// 스타트팀과 링크팀의 능력치 차이를 최소로

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	int N;
	int S[20][20] = {};
	int ans = INT_MAX;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &S[i][j]);

	for (int h = 1; h <= N - 1; h++) {
		vector<int> check;

		// check[i] = 1이면, i번째 학생이 team1
		// check[i] = 0이면, i번째 학생이 team2
		for (int i = 0; i < h; i++) check.push_back(0);
		for (int i = 0; i < N - h; i++) check.push_back(1);

		do {
			vector<int> team1;
			vector<int> team2;
			int team1_stat = 0;
			int team2_stat = 0;

			for (int i = 0; i < N; i++) {
				if (check[i]) team1.push_back(i);
				else team2.push_back(i);
			}

			for (int i = 0; i < team1.size(); i++)
				for (int j = 0; j < team1.size(); j++)
					team1_stat += S[team1[i]][team1[j]];

			for (int i = 0; i < team2.size(); i++)
				for (int j = 0; j < team2.size(); j++)
					team2_stat += S[team2[i]][team2[j]];

			ans = min(ans, abs(team1_stat - team2_stat));

		} while (next_permutation(check.begin(), check.end()));
	
	}

	printf("%d", ans);
}