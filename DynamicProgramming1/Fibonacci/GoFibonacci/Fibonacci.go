package main

import (
	"bufio"
	"fmt"
	"os"
)

func fibonacci(n int) int64 {
	memoization := make([]int64, n+1)

	memoization[0] = 0
	memoization[1] = 1

	for i := 2; i <= n; i++ {
		memoization[i] = memoization[i-1] + memoization[i-2]
	}

	return memoization[n]
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	n := 0
	fmt.Fscanln(br, &n)

	fmt.Fprintln(bw, fibonacci(n))
	bw.Flush()
}
