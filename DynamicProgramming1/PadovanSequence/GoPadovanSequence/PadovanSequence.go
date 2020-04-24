package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	max = 100
)

var (
	padovanSequence [max + 1]int64
)

func getPadovanSequence() {
	padovanSequence[0] = 0
	padovanSequence[1] = 1
	padovanSequence[2] = 1
	padovanSequence[3] = 1

	for i := 4; i <= max; i++ {
		padovanSequence[i] = padovanSequence[i-2] + padovanSequence[i-3]
	}
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	getPadovanSequence()

	t := 0
	fmt.Fscanln(br, &t)

	for i := 0; i < t; i++ {
		n := 0
		fmt.Fscanln(br, &n)
		fmt.Fprintln(bw, padovanSequence[n])
	}

	bw.Flush()
}
