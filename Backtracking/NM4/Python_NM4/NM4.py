import sys

n, m = map(int, sys.stdin.readline().split())
num_list = []


def combination_with_repetition(cnt, cur):
    if cnt == m:
        print(*num_list)
        return

    for i in range(cur, n + 1):
        num_list.append(i)
        combination_with_repetition(cnt + 1, i)
        num_list.pop()


combination_with_repetition(0, 1)
