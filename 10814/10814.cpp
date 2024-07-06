#include <iostream>
#include <algorithm>

using namespace std;

class MemberInfo
{
public:
    int age;
    string name;
    int time; // age가 같을 때 가입 시간을 기준으로 정렬해야 하기 때문
    MemberInfo() {}
    MemberInfo(int age, string name, int time)
    {
        this->age = age;
        this->name = name;
        this->time = time;
    }
    bool operator<(const MemberInfo &member) const
    {
        if (this->age < member.age)
            return true;
        else if (this->age == member.age) // age가 같은 경우 time에 대해 오름차순 정렬
            return this->time < member.time;
        else
            return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    MemberInfo *arr = new MemberInfo[count];

    int age;
    string name;
    int time = 0; // age가 같을 때 가입 시간을 기준으로 정렬해야 하기 때문

    for (int i = 0; i < count; i++)
    {
        cin >> age >> name;
        arr[i] = MemberInfo(age, name, time);
        time++;
    }

    sort(arr, arr + count);

    for (int i = 0; i < count; i++)
        cout << arr[i].age << " " << arr[i].name << '\n';
}