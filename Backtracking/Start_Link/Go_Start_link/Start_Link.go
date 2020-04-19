package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const (
	max = 20
)

var (
	n       = 0
	s       [max][max]int
	team    [max]bool
	minDiff = math.MaxInt64
)

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func getMinDiff(cnt, cur int) {
	if cnt == n/2 {
		startTot := 0
		linkTot := 0

		for i := 0; i < n; i++ {
			for j := i + 1; j < n; j++ {
				if team[i] && team[j] {
					startTot += s[i][j] + s[j][i]
				} else if !team[i] && !team[j] {
					linkTot += s[i][j] + s[j][i]
				}
			}
		}

		minDiff = min(minDiff, abs(startTot-linkTot))

		return
	}

	for i := cur; i < n; i++ {
		if !team[i] {
			team[i] = true
			getMinDiff(cnt+1, i)
			team[i] = false
		}
	}
}

func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(br, &n)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Fscan(br, &s[i][j])
		}
	}

	getMinDiff(0, 1)

	fmt.Fprintln(bw, minDiff)
	bw.Flush()
}
