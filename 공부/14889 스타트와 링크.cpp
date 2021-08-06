#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int N;
int stats[20][20];
vector<int> check;
int ans = INT_MAX;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &stats[i][j]);

	// check[i] = 1이면, i번째 학생이 team1
	// check[i] = 0이면, i번째 학생이 team2
	for (int i = 0; i < N / 2; i++) check.push_back(0);
	for (int i = 0; i < N / 2; i++) check.push_back(1);

	do {
		vector<int> team1;
		vector<int> team2;
		int team1_stat = 0;
		int team2_stat = 0;

		for (int i = 0; i < N; i++) {
			if (check[i]) team1.push_back(i);	
			else team2.push_back(i);
		}

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
				team1_stat += stats[team1[i]][team1[j]];

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
				team2_stat += stats[team2[i]][team2[j]];

		ans = min(ans, abs(team1_stat - team2_stat));

	} while (next_permutation(check.begin(), check.end()));

	printf("%d", ans);
}