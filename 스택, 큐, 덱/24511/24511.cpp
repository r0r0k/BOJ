#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ds_count; // 자료구조 개수
    cin >> ds_count;

    vector<bool> ds(ds_count); // 1 : stack, 0 : queue -> int 대신 bool로 하면 메모리 더 절약 가능
    deque<int> elements;       // 현재 상태의 element들을 저장

    int seq_len; // 수열 길이
    int tmp;     // 임시 저장 변수

    for (int i = 0; i < ds_count; i++)
    {
        cin >> tmp;  // bool을 cin으로 바로 못넘기므로 int tmp에 담아서 저장
        ds[i] = tmp; // 각 index가 차례대로 queue인지 stack인지 저장 : int를 bool에 넣어도 type 바꾸는데 시간 안듬
    }

    for (int i = 0; i < ds_count; i++)
    {
        cin >> tmp; // ds[i] == 1 이어도 cin으로 tmp는 입력받아서 날려줘야함

        if (ds[i] == 1) // stack인 경우 어쩌피 넘겨 받은 값을 pop해서 전달만 하므로 저장할 필요 X
            continue;

        elements.push_back(tmp); // 각 index에 초기 원소가 어떤 값이 들어있는지 저장
    }

    cin >> seq_len;
    while (seq_len--) // queue에서 insert -> pop을 하면 결국 원래 값을 계속 pop해서 이동시키므로 결국 push_front, pop_back의 결과가 됨
    {
        cin >> tmp;
        elements.push_front(tmp);

        cout << elements.back();
        elements.pop_back();

        if (seq_len > 0)
            cout << " ";
    }
}