import sys

count = int(sys.stdin.readline().strip()) # 첫번째 라인에서 입력 값을 정수로 받아옴

lst = list(map(int, sys.stdin.readline().strip().split())) # 입력 값들을 정수로 변환 하기 위해 map 함수 사용 후 list로 변환
# [3, -1 ,2, 3]

sort_list = sorted(list(set(lst))) # set으로 중복 제거 후 sorted로 오름차순 정렬
# [-1, 2, 3]

dic = {} # dict로 선언하면 index(key) 가 음수가 될 수 있기 때문
for i in range(len(sort_list)):
  dic[sort_list[i]] = i # dic의 index가 sort_list의 값이 되고, 해당 sort_list의 값이 dic의 값이 됨
# {-1: 0, 2: 1, 3: 2} -> 각 key에 해당하는 값은 xi'을 나타냄

for i in lst:
  print(dic[i], end=" ")