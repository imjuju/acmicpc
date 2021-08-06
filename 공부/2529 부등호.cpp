#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k;
	vector<char> arr;
	vector<int> small;
	vector<int> big;

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		char temp;
		scanf(" %c", &temp);
		arr.push_back(temp);
	}
	
	for (int i = 0; i < k + 1; i++) {
		small.push_back(i);
		big.push_back(9 - i);
	}

	do {
		int tf = true;
		for (int i = 1; i < k + 1; i++) {
			if (arr[i - 1] == '<') {
				if (big[i - 1] > big[i]) {
					tf = false;
					break;
				}
			}
			else {
				if (big[i - 1] < big[i]) {
					tf = false;
					break;
				}
			}
		}

		if (tf) {
			for (int i = 0; i < k + 1; i++) printf("%d", big[i]);
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	printf("\n");

	do {
		int tf = true;
		for (int i = 1; i < k + 1; i++) {
			if (arr[i - 1] == '<') {
				if (small[i - 1] > small[i]) {
					tf = false;
					break;
				}
			}
			else {
				if (small[i - 1] < small[i]) {
					tf = false;
					break;
				}
			}
		}

		if (tf) {
			for (int i = 0; i < k + 1; i++) printf("%d", small[i]);
			break;
		}
	} while (next_permutation(small.begin(), small.end()));
	
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int k;
bool arr[10];	// '<' = true / '>' = false
int ans[10];
bool check[10];

vector<vector<int> > v;

void func(int idx) {
	if (idx == k + 1) {
		vector<int> temp;
		for (int i = 0; i < k + 1; i++) temp.push_back(ans[i]);
		v.push_back(temp);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!check[i]) {
			check[i] = true;
			ans[idx] = i;


			if (idx == 0) func(idx + 1);
			if (idx >= 1) {
				if (arr[idx - 1]) {
					// 부등호를 만족할 때
					if (ans[idx - 1] < ans[idx]) func(idx + 1);
					
				}
				else {
					// 부등호를 만족할 때
					if (ans[idx - 1] > ans[idx]) func(idx + 1);
				}
			}

			check[i] = false;
		}
	}
	

}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		if (temp == '<') arr[i] = true;
		else arr[i] = false;
	}

	func(0);

	sort(v.begin(), v.end());


	for (int i = 0; i < k + 1; i++) cout << v[v.size() - 1][i];
	cout << '\n';
	for (int i = 0; i < k + 1; i++) cout << v[0][i];
}

*/