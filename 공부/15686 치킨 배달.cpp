// 치킨 거리 = 집과 가장 가까운 치킨집 사이의 거리
// 도시의 치킨 거리 = 모든 집의 치킨 거리의 합

// 0 = 빈 칸, 1 = 집, 2 = 치킨집

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int map[51][51];
int ans = 9999;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<int> check;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) house.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	// check = 0이면 폐업
	// check = 1이면 폐업하지 않음
	for (int i = 0; i < chicken.size() - M; i++) check.push_back(0);
	for (int i = 0; i < M; i++) check.push_back(1);

	do {
		int city_dist = 0;
		vector<pair<int, int> > unclosed;
		for (int i = 0; i < check.size(); i++) 
			if (check[i] == 1) unclosed.push_back({ chicken[i].first,chicken[i].second });
		
		for (int i = 0; i < house.size(); i++) {
			int dist = 9999;
			for (int j = 0; j < unclosed.size(); j++) {
				dist = min(dist, abs(house[i].first - unclosed[j].first) + abs(house[i].second - unclosed[j].second));
			}
			city_dist += dist;
		}

		ans = min(ans, city_dist);

	} while (next_permutation(check.begin(), check.end()));
		
	printf("%d", ans);
}