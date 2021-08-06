// ������ ������ ���� ������ Ǭ��

// 00
//1  2
//1  2
// 33
//4  5
//4  5
// 66

// 0     --   --        --   --   --   --   --   --
// 1  |    |    | |  | |    |       | |  | |  | |  |
// 1  |    |    | |  | |    |       | |  | |  | |  |
// 2     --   --   --   --   --        --   --
// 3  | |       |    |    | |  |    | |  |    | |  |
// 3  | |       |    |    | |  |    | |  |    | |  |
// 4     --   --        --   --        --   --   --


#include <iostream>
#include <string>
using namespace std;

// a[i] = ���� i�� ���� ������ ��� �迭
int a[10][10] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

int main() {
    int s;
    string n;
    cin >> s >> n;

    for (int i = 0; i <= 4; i++) {
        if (i == 0 || i == 2 || i == 4) {
            for (int j = 0; j < n.size(); j++) {
                // ���� ����
                int now = n[j] - '0';
            
                cout << ' ';

                if (i == 0 && a[now][0])
                    for (int k = 0; k < s; k++) cout << '-';

                else if (i == 2 && a[now][3])
                    for (int k = 0; k < s; k++) cout << '-';

                else if (i == 4 && a[now][6])
                    for (int k = 0; k < s; k++) cout << '-';

                else
                    for (int k = 0; k < s; k++) cout << ' ';

                cout << ' ';


                // �� ������ ���̿��� ������ �� ĭ �־�� �Ѵ�
                cout << ' ';
            }
            cout << '\n';
        }

        else {
            // '|'�� s�� �־�� �Ѵ�
            for (int h = 0; h < s; h++) {
                for (int j = 0; j < n.size(); j++) {
                    // ���� ����
                    int now = n[j] - '0';

                    if (i == 1 && a[now][1]) cout << '|';
                    else if (i == 3 && a[now][4]) cout << '|';
                    else cout << ' ';

                    for (int k = 0; k < s; k++) cout << ' ';

                    if (i == 1 && a[now][2]) cout << '|';
                    else if (i == 3 && a[now][5]) cout << '|';
                    else cout << ' ';

                    // �� ������ ���̿��� ������ �� ĭ �־�� �Ѵ�
                    cout << ' ';
                }
                cout << '\n';
            }
        }


    
    }


}