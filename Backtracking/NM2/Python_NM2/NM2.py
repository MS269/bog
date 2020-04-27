import sys

MAX = 8 + 1

n, m = map(int, sys.stdin.readline().split())
num_list = []
check_list = [False for _ in range(MAX)]


def combination(cnt, cur):
    if cnt == m:
        print(*num_list)
        return

    for i in range(cur, n + 1):
        if not check_list[i]:
            num_list.append(i)
            check_list[i] = True
            combination(cnt + 1, i + 1)
            num_list.pop()
            check_list[i] = False


combination(0, 1)
