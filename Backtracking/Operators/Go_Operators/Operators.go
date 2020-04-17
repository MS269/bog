package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var (
	n         = 0
	numbers   []int
	operators [4]int
	maxNum    = -1000000000
	minNum    = 1000000000
)

func insertOperators(num, add, sub, mul, div, cnt int) {
	if cnt == n {
		maxNum = int(math.Max(float64(maxNum), float64(num)))
		minNum = int(math.Min(float64(minNum), float64(num)))
		return
	}

	if add != 0 {
		insertOperators(num+numbers[cnt], add-1, sub, mul, div, cnt+1)
	}
	if sub != 0 {
		insertOperators(num-numbers[cnt], add, sub-1, mul, div, cnt+1)
	}
	if mul != 0 {
		insertOperators(num*numbers[cnt], add, sub, mul-1, div, cnt+1)
	}
	if div != 0 {
		insertOperators(num/numbers[cnt], add, sub, mul, div-1, cnt+1)
	}
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(br, &n)

	numbers = make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(br, &numbers[i])
	}

	for i := 0; i < 4; i++ {
		fmt.Fscan(br, &operators[i])
	}

	insertOperators(numbers[0], operators[0], operators[1], operators[2], operators[3], 1)

	fmt.Fprintln(bw, maxNum)
	fmt.Fprintln(bw, minNum)

	bw.Flush()
}
