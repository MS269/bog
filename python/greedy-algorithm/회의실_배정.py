n = int(input())
times = [list(map(int, input().split())) for _ in range(n)]

# 정렬
times.sort()

result = 0
end = 0
for time in times:
    # 시작 시간이 배정된 끝나는 시간보다 같거나 작으면 배정
    if time[0] >= end:
        result += 1
        end = time[1]
    # 끝나는 시간이 배정된 끝나는 시간보다 작으면 재배정
    elif time[1] < end:
        end = time[1]

print(result)
