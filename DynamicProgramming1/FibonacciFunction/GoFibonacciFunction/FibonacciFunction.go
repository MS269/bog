package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	max = 41
)

var (
	memo0 [max]int
	memo1 [max]int
)

func fibonacciFunction() {
	memo0[0] = 1
	memo1[0] = 0
	memo0[1] = 0
	memo1[1] = 1

	for i := 2; i < max; i++ {
		memo0[i] = memo0[i-1] + memo0[i-2]
		memo1[i] = memo1[i-1] + memo1[i-2]
	}
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	fibonacciFunction()

	t := 0
	fmt.Fscanln(br, &t)

	for i := 0; i < t; i++ {
		n := 0
		fmt.Fscanln(br, &n)
		fmt.Fprintf(bw, "%d %d\n", memo0[n], memo1[n])
	}

	bw.Flush()
}
