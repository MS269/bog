package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	max = 1000000
	mod = 15746
)

var (
	n int
	d [max + 1]int
)

func tiles() {
	d[0] = 0
	d[1] = 1
	d[2] = 2

	for i := 3; i <= n; i++ {
		d[i] = (d[i-1] + d[i-2]) % mod
	}
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(br, &n)

	tiles()

	fmt.Fprintln(bw, d[n])
	bw.Flush()
}
