import sys

MOD = 15746

n = int(sys.stdin.readline())
d = [0, 1, 2]


def tiles():
    for i in range(3, n + 1):
        d.append((d[i - 1] + d[i - 2]) % MOD)


tiles()

print(d[n])
