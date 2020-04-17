package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	br     = bufio.NewReader(os.Stdin)
	bw     = bufio.NewWriter(os.Stdout)
	matrix [9][9]int
	row    [9][10]bool
	column [9][10]bool
	square [9][10]bool
)

func getSquare(a, b int) int { return a/3*3 + b/3 }

func initSudoku() {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Fscan(br, &matrix[i][j])

			if matrix[i][j] != 0 {
				row[i][matrix[i][j]] = true
				column[j][matrix[i][j]] = true
				square[getSquare(i, j)][matrix[i][j]] = true
			}
		}
	}
}

func printSudoku() {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Fprintf(bw, "%d ", matrix[i][j])
		}
		fmt.Fprintln(bw)
	}
	bw.Flush()
}

func solveSudoku(cnt int) {
	if cnt == 81 {
		printSudoku()
		os.Exit(0)
	}

	x := cnt / 9
	y := cnt % 9

	if matrix[x][y] == 0 {
		for i := 1; i < 10; i++ {
			if !row[x][i] && !column[y][i] && !square[getSquare(x, y)][i] {
				matrix[x][y] = i
				row[x][i] = true
				column[y][i] = true
				square[getSquare(x, y)][i] = true
				solveSudoku(cnt + 1)
				matrix[x][y] = 0
				row[x][i] = false
				column[y][i] = false
				square[getSquare(x, y)][i] = false
			}
		}
	} else {
		solveSudoku(cnt + 1)
	}
}

func main() {
	initSudoku()

	solveSudoku(0)
}
