import sys


n, ans = int(sys.stdin.readline()), 0
height = [False] * n
down_top_diagonal = [False] * (2 * n - 1)
top_down_diagonal = [False] * (2 * n - 1)


def n_queen(i):
    global ans

    if i == n:
        ans += 1
        return

    for j in range(n):
        if height[j] or down_top_diagonal[i+j] or top_down_diagonal[i-j+n-1]:
            continue

        height[j] = down_top_diagonal[i+j] = top_down_diagonal[i-j+n-1] = True
        n_queen(i + 1)
        height[j] = down_top_diagonal[i+j] = top_down_diagonal[i-j+n-1] = False


n_queen(0)

print(ans)
