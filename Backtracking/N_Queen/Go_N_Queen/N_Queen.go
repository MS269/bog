package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	max = 14
)

var (
	n               = 0
	ans             = 0
	height          [max]bool
	downTopDiagonal [2*max - 1]bool
	topDownDiagonal [2*max - 1]bool
)

func nQueen(i int) {
	if i == n {
		ans++
		return
	}

	for j := 0; j < n; j++ {
		if height[j] || downTopDiagonal[i+j] || topDownDiagonal[i-j+n-1] {
			continue
		}

		height[j] = true
		downTopDiagonal[i+j] = true
		topDownDiagonal[i-j+n-1] = true
		nQueen(i + 1)
		height[j] = false
		downTopDiagonal[i+j] = false
		topDownDiagonal[i-j+n-1] = false
	}
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(br, &n)

	nQueen(0)

	fmt.Fprintln(bw, ans)
	bw.Flush()
}
