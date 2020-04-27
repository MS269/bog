import sys

n = int(sys.stdin.readline())


def fibonacci(n):
    memoization = [0 for _ in range(n + 1)]
    memoization[0] = 0
    memoization[1] = 1
    for i in range(2, n + 1):
        memoization[i] = memoization[i - 1] + memoization[i - 2]
    return memoization[n]


print(fibonacci(n))
