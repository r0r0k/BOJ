#include <iostream>
using namespace std;

int n;
int arr[1000000]; // 수열을 저장하는 배열
int cmp[1000000]; // 가장 긴 증가하는 부분 수열을 찾기 위한 배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cmp[0] = arr[0]; // 초기값 설정
    int end_idx = 0; // 마지막 원소를 가리키는 index : 가장 긴 증가하는 부분 수열을 유지하기 위해서 필요 (가장 긴 증가하는 부분 수열의 길이 - 1)

    for (int i = 1; i < n; i++) // arr의 모든 원소를 순회
    {
        if (cmp[end_idx] < arr[i]) // arr[i]가 현재 cmp의 마지막 원소보다 큰 경우 idx 뒤에 insert (이미 원소가 있었다면 대체)
            cmp[++end_idx] = arr[i];

        else if (cmp[end_idx] == arr[i]) // arr[i]가 cmp의 마지막 원소와 같은 경우 넘어가면 됨
            continue;

        else // arr[i]가 cmp의 마지막 원소보다 작은 경우
        {
            int left = 0;        // cmp의 시작 index
            int right = end_idx; // cmp의 끝 index
            int mid;             // cmp에서 arr[i]와 차이가 가장 작으면서 값이 큰 index (또는 값이 같은 index)
            int res;             // mid를 저장할 변수

            while (left <= right)
            {
                mid = (left + right) / 2;

                if (arr[i] < cmp[mid]) // 넣고자 하는 arr[i]가 cmp[mid] 보다 작으면 일단 해당 mid가 후보가 되므로 res에 저장 후, mid를 더 줄여봄
                {
                    res = mid;
                    right = mid - 1;
                }

                if (arr[i] == cmp[mid]) // 넣고자 하는 arr[i]가 cmp[mid]와 같은 경우, 바로 여기에 넣으면 되기 때문에 res에 넣은 후 break로 이진 탐색을 탈출
                {
                    res = mid;
                    break;
                }

                if (arr[i] > cmp[mid]) // 넣고자 하는 arr[i]가 cmp[mid]보다 큰 경우, 해당 위치에는 넣을 수 없기 때문에 mid를 키워서 cmp[mid]의 후보를 키워야함
                {
                    left = mid + 1;
                }
            }

            cmp[res] = arr[i]; // 찾은 index에 arr[i]를 대입 : insert가 아닌 값 대체
        }
    }

    cout << end_idx + 1; // 마지막 (index + 1)이 길이가 됨

    return 0;
}