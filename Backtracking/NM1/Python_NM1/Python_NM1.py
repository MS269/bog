import sys


MAX = 8 + 1

n, m = map(int, sys.stdin.readline().split())
num_list = []
check_list = [False for _ in range(MAX)]


def permutation(cnt):
    if cnt == m:
        print(*num_list)
        return

    for i in range(1, n + 1):
        if not check_list[i]:
            num_list.append(i)
            check_list[i] = True
            permutation(cnt + 1)
            num_list.pop()
            check_list[i] = False


permutation(0)
