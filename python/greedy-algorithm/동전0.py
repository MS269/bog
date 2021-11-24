n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

# 역순
coins.reverse()

# 비싼 동전부터 사용
result = 0
for coin in coins:
    result += k // coin
    k %= coin

print(result)
