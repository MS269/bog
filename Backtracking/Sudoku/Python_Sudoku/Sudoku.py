import sys


matrix = list(list(map(int, sys.stdin.readline().split())) for _ in range(9))
row = [[False for _ in range(10)] for _ in range(9)]
column = [[False for _ in range(10)] for _ in range(9)]
square = [[False for _ in range(10)] for _ in range(9)]


def get_square(a, b):
    return a // 3 * 3 + b // 3


def init_sudoku():
    for i in range(9):
        for j in range(9):
            if matrix[i][j] != 0:
                row[i][matrix[i][j]] = True
                column[j][matrix[i][j]] = True
                square[get_square(i, j)][matrix[i][j]] = True


def print_sudoku():
    for r in matrix:
        print(*r)


def solve_sudoku(cnt):
    if cnt == 81:
        print_sudoku()
        exit()

    x = cnt // 9
    y = cnt % 9

    if matrix[x][y] == 0:
        for i in range(1, 10):
            if not row[x][i] and not column[y][i] and not square[get_square(x, y)][i]:
                matrix[x][y] = i
                row[x][i] = column[y][i] = square[get_square(x, y)][i] = True
                solve_sudoku(cnt + 1)
                matrix[x][y] = 0
                row[x][i] = column[y][i] = square[get_square(x, y)][i] = False
    else:
        solve_sudoku(cnt + 1)


init_sudoku()

solve_sudoku(0)
