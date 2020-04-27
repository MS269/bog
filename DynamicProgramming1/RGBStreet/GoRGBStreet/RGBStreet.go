package main

import (
	"bufio"
	"fmt"
	"os"
)

type cost struct {
	r int
	g int
	b int
}

const (
	max = 1000
)

var (
	costList [max + 1]cost
)

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	n := 0
	fmt.Fscanln(br, &n)

	for i := 1; i <= n; i++ {
		temp := cost{0, 0, 0}
		fmt.Fscanln(br, &temp.r, &temp.g, &temp.b)

		costList[i].r = temp.r + min(costList[i-1].g, costList[i-1].b)
		costList[i].g = temp.g + min(costList[i-1].r, costList[i-1].b)
		costList[i].b = temp.b + min(costList[i-1].r, costList[i-1].g)
	}

	minCost := min(min(costList[n].r, costList[n].g), costList[n].b)

	fmt.Fprintln(bw, minCost)
	bw.Flush()
}
