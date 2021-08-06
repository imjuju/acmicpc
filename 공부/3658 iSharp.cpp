#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	string str;
	vector<string> v;
	vector<string> ans;
	getline(cin, str);

	string temp = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ' || str[i] == ',' || str[i] == ';') {
			if (temp != "") {
				v.push_back(temp);
				temp = "";
			}
		}
		else {
			temp += str[i];
		}
	}

	for (int i = 1; i < v.size(); i++) {
		// 기본 변수형 출력
		cout << v[0];

		// 추가 변수형 출력
		int var_idx = 0;	// 변수 이름의 끝 인덱스
		for (int j = v[i].size() - 1; j >= 0; j--) {
			if (v[i][j] == '&') cout << "&";
			else if (v[i][j] == '*') cout << "*";
			else if (v[i][j] == '[') cout << "]";
			else if (v[i][j] == ']') cout << "[";
			else {
				var_idx = j;
				break;
			}

		}

		cout << " ";

		// 변수 이름 출력
		for (int j = 0; j <= var_idx; j++) {
			cout << v[i][j];
		}
		
		cout << ";\n";
	}
}