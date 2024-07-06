```
// 11650번

#include <iostream>
#include <algorithm>

using namespace std;

class Coordinate
{
public:
    int x;
    int y;

    Coordinate() {} // Default constructor
    Coordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    const bool operator<(const Coordinate &coordinate) const
    // sort의 경우 overloading에 const keyword가 없으면 컴파일 에러가 발생
    // 첫번째 const는 return 값이 도중에 변경되지 않는 것을 보장
    // 두번째 const는 parameter의 값이 변경되지 않는 것을 보장
    // 세번째 const는 this-> 멤버의 값이 변경되지 않는 것을 보장

    // c++에서 &(reference)로 parameter를 전달하는 이유는 불필요한 객체 복사를 막기 위함
    // coordinate의 크기가 매우 커지면 복사하는데 시간이 많이 듬
    // 대신 reference가 아니라 parameter의 const는 필요 X
    {
        if (this->x < coordinate.x) // x를 오름차순으로 정렬
            return true;

        else if (this->x == coordinate.x) // x가 같은 경우 y에 따라 오름차순으로 정렬
            return this->y < coordinate.y;
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

    Coordinate *c = new Coordinate[count];

    int x, y;
    for (int i = 0; i < count; i++)
    {
        cin >> x >> y;
        c[i] = Coordinate(x, y);
    }

    sort(c, c + count);

    for (int i = 0; i < count; i++)
        cout << c[i].x << ' ' << c[i].y << '\n';

    delete[] c;
}```