import sys


n, m = map(int, sys.stdin.readline().split())
num_list = []


def permutation_with_repetition(cnt):
    if cnt == m:
        print(*num_list)
        return

    for i in range(1, n + 1):
        num_list.append(i)
        permutation_with_repetition(cnt + 1)
        num_list.pop()


permutation_with_repetition(0)
