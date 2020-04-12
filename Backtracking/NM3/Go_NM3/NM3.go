package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	max = 7 + 1
)

var (
	br      = bufio.NewReader(os.Stdin)
	bw      = bufio.NewWriter(os.Stdout)
	n, m    int
	numList [max]int
)

func permutationWithRepetition(cnt int) {
	if cnt == m {
		for i := 0; i < m; i++ {
			fmt.Fprintf(bw, "%d ", numList[i])
		}
		fmt.Fprintln(bw)
		return
	}

	for i := 1; i <= n; i++ {
		numList[cnt] = i
		permutationWithRepetition(cnt + 1)
	}
}

func main() {
	defer bw.Flush()

	fmt.Fscanln(br, &n, &m)

	permutationWithRepetition(0)
}
