#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ds_count; // 자료구조 개수
    cin >> ds_count;

    vector<bool> ds(ds_count);      // 1 : stack, 0 : queue -> int 대신 bool로 하면 메모리 더 절약 가능
    vector<int> elements(ds_count); // 현재 상태의 element들을 저장

    int seq_len; // 수열 길이
    int tmp;     // 임시 저장 변수
    int trans;   // 각 ds에서 뒤로 전달할 변수

    for (int i = 0; i < ds_count; i++)
    {
        cin >> tmp;  // bool을 cin으로 바로 못넘기므로 int tmp에 담아서 저장
        ds[i] = tmp; // 각 index가 차례대로 queue인지 stack인지 저장 : int를 bool에 넣어도 type 바꾸는데 시간 안듬
    }

    for (int i = 0; i < ds_count; i++)
        cin >> elements[i]; // 각 index에 초기 원소가 어떤 값이 들어있는지 저장

    cin >> seq_len;
    while (seq_len--)
    {
        // insert -> pop
        cin >> trans;
        for (int i = 0; i < ds_count; i++)
        {
            if (ds[i] == true) // stack인 경우 : insert 후 pop하면 tmp가 pop되므로 그냥 trans를 계속
                continue;

            else // queue인 경우 : insert 후 pop 하면 기존 값이 pop됨
            {
                tmp = trans;
                trans = elements[i]; // 기존 값
                elements[i] = tmp;   // tmp는 insert
            }
        }

        cout << trans; // 최종 trans를 print
        if (seq_len > 0)
            cout << " ";
    }
}