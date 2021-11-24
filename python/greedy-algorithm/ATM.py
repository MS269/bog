n = int(input())
p = list(map(int, input().split()))

# 정렬
p.sort()

# 각 사람들이 기다릴 시간 계산
for i in range(0, n - 1):
    p[i + 1] += p[i]

# 사람들이 기다리는 시간 총합
result = sum(p)
print(result)
