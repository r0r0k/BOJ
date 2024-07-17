# 실패율 - `failure_rate.cpp`

1. 각 stage에 도달한 플레이어 수를 저장하는 vector 선언 : `arrive_stages`

2. 각 stage에 들어와 있는(해당 stage를 깨지 못한) 플레이어 수 저장 : `not_clear_user`

3. 반복문을 돌며 `arrive_stages`에 누적해서 저장, `not_clear_user`에 해당 stage에 들어와 있는 플레이어만 저장

4. <실패율, stage>를 저장하는 `vector<pair<double, int>> rates` 선언 \
: `map` 으로 선언하면 바로 정렬은 되겠지만, 실패율에 해당하는 `key`가 중복인 경우를 처리하지 못하기 때문에 `pair`를 가지는 `vector`로 선언

- stage를 `key`로 가지고 실패율을 `value`로 가지는 map을 선언하더라도 `value`에 따라 정렬하는 것은 불가능하기 때문에 vector로 선언하는게 나음

5. 실패율과 stage를 계산하고 아래와 같이 정렬 기준을 정하는 `cmp` 함수를 통해 `sort`

- `pair`는 `map`처럼 `it.first`, `it.second`로 접근 가능

- `tuple`은 `pair`와 달리 3개 이상을 저장할 수 있고, `get<index>(변수명)`으로 접근 가능함 Ex) `get<1>(my_tuple)` 

```
// vector에 사용
bool cmp(const pair<double, int> &a, const pair<double, int> &b)
{
    if (a.first == b.first) // failure_rate가 같다면, stage를 오름차순으로 저장
        return a.second < b.second;
    return a.first > b.first; // failure_rate를 내림차순으로 저장
}
```

- `set`, `map`은 `key`에 대해서 선언과 동시에 아래와 같이 `struct cmp`로 sort 가능하지만 `vector`는 안됨 (당연히 `pair`도 안됨)

```
struct cmp
{
    bool operator()(const pair<double, int> &a, const pair<double, int> &b)
    {
        if (a.first == b.first) // failure_rate가 같다면, stage를 오름차순으로 저장
            return a.second < b.second;
        return a.first > b.first; // failure_rate를 내림차순으로 저장
    }
};
```

6. `sort` 된 vector의 stage를 `answer`에 대입

