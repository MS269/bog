package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	max = 8 + 1
)

var (
	br      = bufio.NewReader(os.Stdin)
	bw      = bufio.NewWriter(os.Stdout)
	n, m    int
	numList [max]int
)

func combinationWithRepetition(cnt, cur int) {
	if cnt == m {
		for i := 0; i < m; i++ {
			fmt.Fprintf(bw, "%d ", numList[i])
		}
		fmt.Fprintln(bw)
		return
	}

	for i := cur; i <= n; i++ {
		numList[cnt] = i
		combinationWithRepetition(cnt+1, i)
	}
}

func main() {
	defer bw.Flush()

	fmt.Fscanln(br, &n, &m)

	combinationWithRepetition(0, 1)
}
