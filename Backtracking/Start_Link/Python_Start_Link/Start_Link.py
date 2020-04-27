import sys
from itertools import combinations

n = int(sys.stdin.readline())
s = list(list(map(int, sys.stdin.readline().split())) for _ in range(n))
min_diff = sys.maxsize


def get_min_diff():
    global min_diff

    cand_list = [i for i in range(n)]
    for cand in combinations(cand_list, n // 2):
        start_members = list(cand)
        link_members = list(set(cand_list) - set(cand))

        start_comb = list(combinations(start_members, 2))
        link_comb = list(combinations(link_members, 2))

        start_tot = 0
        for x, y in start_comb:
            start_tot += (s[x][y] + s[y][x])

        link_tot = 0
        for x, y in link_comb:
            link_tot += (s[x][y] + s[y][x])

        min_diff = min(min_diff, abs(start_tot - link_tot))


get_min_diff()

print(min_diff)
