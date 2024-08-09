#include <iostream>
using namespace std;

int n;
bool matrix[64][64];
string res = "";

void recursion(int row, int col, int n)
{
    bool flag = false;             // 사각형 내에 다른 값이 있는지 확인하는 리flag
    bool first = matrix[row][col]; // first는 첫번째 값으로 지정
    for (int i = row; i < row + n; i++)
    {
        for (int j = col; j < col + n; j++)
        {
            if (first != matrix[i][j]) // first와 matrix가 달라지는 경우
            {
                flag = true; // flag 설정 후 break
                break;
            }
        }
        if (flag == true) // flag가 설정되면 break
            break;
    }

    if (flag == false)
    {
        first == true ? res += '1' : res += '0'; // first가 true이면 1, 아니면 0추가
    }

    else
    {
        res += '(';
        // 순서를 지켜야함
        recursion(row, col, n / 2);                 // 왼쪽 위
        recursion(row, col + n / 2, n / 2);         // 오른쪽 위
        recursion(row + n / 2, col, n / 2);         // 왼쪽 아래
        recursion(row + n / 2, col + n / 2, n / 2); // 오른쪽 아래
        res += ')';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
            matrix[i][j] = line[j] - '0'; // atoi는 c언어, stoi는 c++
    }

    recursion(0, 0, n);

    cout << res;
    return 0;
}