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
	br        = bufio.NewReader(os.Stdin)
	bw        = bufio.NewWriter(os.Stdout)
	n, m      int
	numList   [max]int
	checkList [max]bool
)

func permutation(cnt int) {
	if cnt == m {
		for i := 0; i < m; i++ {
			fmt.Fprintf(bw, "%d ", numList[i])
		}
		fmt.Fprintln(bw)
		return
	}

	for i := 1; i <= n; i++ {
		if !checkList[i] {
			numList[cnt] = i
			checkList[i] = true
			permutation(cnt + 1)
			checkList[i] = false
		}
	}
}

func main() {
	defer bw.Flush()

	fmt.Fscanln(br, &n, &m)

	permutation(0)
}
