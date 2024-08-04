#include <iostream>
#include <vector>
using namespace std;

vector<int> number;
vector<char> op;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line; // 입력 받은 식
    cin >> line;

    string tmp = ""; // 정수를 임시 저장할 문자열
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '+' || line[i] == '-') // 연산자를 만나면 연산자를 op에 넣어주고 number에 tmp에 저장한 문자열을 정수로 변환하여 넣어줌
        {
            op.push_back(line[i]);
            number.push_back(stoi(tmp)); // stoi는 "0009"도 알아서 9로 변환해줌
            tmp = "";
        }

        else // 연산자를 만나지 않으면 계속 tmp에 숫자를 쌓아서 계산할 정수값을 만들어줌
            tmp += line[i];
    }
    number.push_back(stoi(tmp)); // 마지막 숫자는 '+' 또는 '-' 를 안만나기 때문에 직접 넣어줘야함

    int res = number[0]; // 식의 결과 값 : 처음에 오는 수는 무조건 +로 더해지므로 미리 대입해주고, 뒤에서 number는 (i + 1)로 접근

    bool sub_flag = false; // '-' 연산자가 나온 적이 있는지 확인하는 flag (false는 아직 만나지 않은 상태)
    for (int i = 0; i < op.size(); i++)
    {
        if (sub_flag == false && op[i] == '-') // 처음 '-'를 만나면 무조건 이후엔 계속 -연산 진행
            sub_flag = true;

        if (sub_flag == true) // '-'를 만난 경우
            res -= number[i + 1];
        else // '-'를 아직 만나지 않은 경우
            res += number[i + 1];
    }

    cout << res;

    return 0;
}