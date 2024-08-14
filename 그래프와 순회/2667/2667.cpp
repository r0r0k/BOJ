#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int matrix[27][27]; // 1-index에 overflow 방지를 위해 끝 인덱스에 사이즈 1추가
int cnt = 0;
vector<int> house_cnt;

void dfs(int row, int col)
{
    cnt++;
    matrix[row][col] = 0;

    if (matrix[row - 1][col] == 1) // 상
        dfs(row - 1, col);

    if (matrix[row + 1][col] == 1) // 하
        dfs(row + 1, col);

    if (matrix[row][col - 1] == 1) // 좌
        dfs(row, col - 1);

    if (matrix[row][col + 1] == 1) // 우
        dfs(row, col + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string line;
    for (int i = 1; i <= n; i++)
    {
        cin >> line;
        for (int j = 1; j <= n; j++)
            matrix[i][j] = line[j - 1] - '0'; // 1-index이기때문
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == 1)
            {
                dfs(i, j);
                house_cnt.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(house_cnt.begin(), house_cnt.end());

    cout << house_cnt.size() << '\n';
    for (auto it : house_cnt)
        cout << it << '\n';

    return 0;
}