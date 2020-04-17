using System;

namespace CS_Sudoku
{
    class Sudoku
    {
        static int[,] matrix = new int[9, 9];
        static bool[,] row = new bool[9, 10];
        static bool[,] column = new bool[9, 10];
        static bool[,] square = new bool[9, 10];

        static int GetSquare(int a, int b)
        {
            return a / 3 * 3 + b / 3;
        }

        static void InitSudoku()
        {
            for (int i = 0; i < 9; i++)
            {
                string[] s = Console.ReadLine().Split();
                for (int j = 0; j < 9; j++)
                {
                    matrix[i, j] = Convert.ToInt32(s[j]);
                    if (matrix[i, j] != 0)
                    {
                        row[i, matrix[i, j]] = true;
                        column[j, matrix[i, j]] = true;
                        square[GetSquare(i, j), matrix[i, j]] = true;
                    }
                }
            }
        }

        static void PrintSudoku()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                    Console.Write("{0} ", matrix[i, j]);
                Console.WriteLine();
            }
        }

        static void SolveSudoku(int cnt)
        {
            if (cnt == 81)
            {
                PrintSudoku();
                Environment.Exit(0);
            }

            int x = cnt / 9;
            int y = cnt % 9;

            if (matrix[x, y] == 0)
            {
                for (int i = 1; i < 10; i++)
                {
                    if (!row[x, i] && !column[y, i] && !square[GetSquare(x, y), i])
                    {
                        matrix[x, y] = i;
                        row[x, i] = true;
                        column[y, i] = true;
                        square[GetSquare(x, y), i] = true;
                        SolveSudoku(cnt + 1);
                        matrix[x, y] = 0;
                        row[x, i] = false;
                        column[y, i] = false;
                        square[GetSquare(x, y), i] = false;
                    }
                }
            }
            else
                SolveSudoku(cnt + 1);
        }

        static void Main(string[] args)
        {
            InitSudoku();

            SolveSudoku(0);
        }
    }
}
