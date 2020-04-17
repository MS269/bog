#include <stdio.h>
#include <stdlib.h>

#define GET_SQUARE(a, b) a / 3 * 3 + b / 3

int matrix[9][9];
int row[9][10];
int column[9][10];
int square[9][10];

void init_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf_s("%d", &matrix[i][j]);

            if (matrix[i][j])
            {
                row[i][matrix[i][j]] = column[j][matrix[i][j]] = 1;
                square[GET_SQUARE(i, j)][matrix[i][j]] = 1;
            }
        }
    }
}

void print_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void solve_sudoku(int cnt)
{
    if (cnt == 81)
    {
        print_sudoku();
        exit(0);
    }

    int x = cnt / 9;
    int y = cnt % 9;

    if (!matrix[x][y])
    {
        for (int i = 1; i < 10; i++)
        {
            if (!row[x][i] && !column[y][i] && !square[GET_SQUARE(x, y)][i])
            {
                matrix[x][y] = i;
                row[x][i] = column[y][i] = square[GET_SQUARE(x, y)][i] = 1;
                solve_sudoku(cnt + 1);
                matrix[x][y] = 0;
                row[x][i] = column[y][i] = square[GET_SQUARE(x, y)][i] = 0;
            }
        }
    }
    else
        solve_sudoku(cnt + 1);
}

int main()
{
    init_sudoku();

    solve_sudoku(0);

    return 0;
}
