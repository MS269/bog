import sys


MAX = 41
memo_0 = [1, 0]
memo_1 = [0, 1]


def fibonacci_function():
    for i in range(2, MAX):
        memo_0.append(memo_0[i - 1] + memo_0[i - 2])
        memo_1.append(memo_1[i - 1] + memo_1[i - 2])


fibonacci_function()

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    print(memo_0[n], memo_1[n])
