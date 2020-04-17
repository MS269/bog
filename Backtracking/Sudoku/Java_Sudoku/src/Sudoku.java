import java.io.*;
import java.util.StringTokenizer;

public class Sudoku {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[][] matrix = new int[9][9];
    static boolean[][] row = new boolean[9][10];
    static boolean[][] column = new boolean[9][10];
    static boolean[][] square = new boolean[9][10];

    static int getSquare(int a, int b) {
        return a / 3 * 3 + b / 3;
    }

    static void initSudoku() throws IOException {
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());

                if (matrix[i][j] != 0) {
                    row[i][matrix[i][j]] = true;
                    column[j][matrix[i][j]] = true;
                    square[getSquare(i, j)][matrix[i][j]] = true;
                }
            }
        }
    }

    static void printSudoku() throws IOException {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                bw.write(matrix[i][j] + " ");
            bw.newLine();
        }
        bw.flush();
    }

    static void solveSudoku(int cnt) throws IOException {
        if (cnt == 81) {
            printSudoku();
            System.exit(0);
        }

        int x = cnt / 9;
        int y = cnt % 9;

        if (matrix[x][y] == 0) {
            for (int i = 1; i < 10; i++) {
                if (!row[x][i] && !column[y][i] && !square[getSquare(x, y)][i]) {
                    matrix[x][y] = i;
                    row[x][i] = true;
                    column[y][i] = true;
                    square[getSquare(x, y)][i] = true;
                    solveSudoku(cnt + 1);
                    matrix[x][y] = 0;
                    row[x][i] = false;
                    column[y][i] = false;
                    square[getSquare(x, y)][i] = false;
                }
            }
        } else
            solveSudoku(cnt + 1);
    }

    public static void main(String[] args) throws IOException {
        initSudoku();

        solveSudoku(0);
    }
}
