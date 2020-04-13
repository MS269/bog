#include <stdio.h>

#define MAX 14

int n, ans;
int height[MAX], down_top_diagonal[2 * MAX - 1], top_down_diagonal[2 * MAX - 1];

void n_queen(int i)
{
	if (i == n)
	{
		ans++;
		return;
	}

	for (int j = 0; j < n; j++)
	{
		if (height[j] || down_top_diagonal[i + j] || top_down_diagonal[i - j + n - 1])
			continue;

		height[j] = down_top_diagonal[i + j] = top_down_diagonal[i - j + n - 1] = 1;
		n_queen(i + 1);
		height[j] = down_top_diagonal[i + j] = top_down_diagonal[i - j + n - 1] = 0;
	}
}

int main()
{
	scanf_s("%d", &n);

	n_queen(0);

	printf("%d\n", ans);

	return 0;
}
