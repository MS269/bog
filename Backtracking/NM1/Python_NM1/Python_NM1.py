import sys


MAX = 8 + 1

n, m = map(int, sys.stdin.readline().split())
numList = []
checkList = [False for _ in range(MAX)]


def permutation(cnt):
    if cnt == m:
        print(*numList)
        return

    for i in range(1, n + 1):
        if not checkList[i]:
            numList.append(i)
            checkList[i] = True
            permutation(cnt + 1)
            numList.pop()
            checkList[i] = False


permutation(0)
