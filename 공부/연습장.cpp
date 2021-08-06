#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    vector<int> v;

    v.push_back(3);
    v.push_back(1);
    v.push_back(2);

    //sort(v.begin(), v.end());

    //sort(v.begin(), v.begin() + 10);


    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}