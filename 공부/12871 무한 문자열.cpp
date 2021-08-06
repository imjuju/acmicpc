#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	
	if (s.size() == t.size()) {
		if (s == t) cout << 1;
		else cout << 0;
		
		return 0;
	}

	string S, T;
	
	for (int i = 0; i < t.size(); i++) S += s;
	for (int i = 0; i < s.size(); i++) T += t;

	if (S == T) cout << 1;
	else cout << 0;
}