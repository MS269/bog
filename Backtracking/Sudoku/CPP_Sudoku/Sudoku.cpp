#include <iostream>
#include <cstdlib>

#define GET_SQURE(a, b) a / 3 * 3 + b / 3

using namespace std;

int matrix[9][9];
bool row[9][10];
bool column[9][10];
bool square[9][10];

void init_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> matrix[i][j];

            if (matrix[i][j])
            {
                row[i][matrix[i][j]] = column[j][matrix[i][j]] = true;
                square[GET_SQURE(i, j)][matrix[i][j]] = true;
            }
        }
    }
}

void print_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
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
            if (!row[x][i] && !column[y][i] && !square[GET_SQURE(x, y)][i])
            {
                matrix[x][y] = i;
                row[x][i] = column[y][i] = square[GET_SQURE(x, y)][i] = true;
                solve_sudoku(cnt + 1);
                matrix[x][y] = 0;
                row[x][i] = column[y][i] = square[GET_SQURE(x, y)][i] = false;
            }
        }
    }
    else
        solve_sudoku(cnt + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init_sudoku();

    solve_sudoku(0);

    return 0;
}
