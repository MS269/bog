import sys

n = int(sys.stdin.readline())
cost = [[0, 0, 0]]

for i in range(1, n + 1):
    temp = list(map(int, sys.stdin.readline().split()))

    temp[0] += min(cost[i - 1][1], cost[i - 1][2])
    temp[1] += min(cost[i - 1][0], cost[i - 1][2])
    temp[2] += min(cost[i - 1][0], cost[i - 1][1])

    cost.append(temp)

print(min(cost[n]))
