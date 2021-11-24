n = int(input())
dists = list(map(int, input().split()))
costs = list(map(int, input().split()))

# 매 주유소마다 싼 가격으로 구매
result = 0
min_cost = costs[0]
for i in range(n - 1):
    min_cost = min(min_cost, costs[i])
    result += min_cost * dists[i]

print(result)
