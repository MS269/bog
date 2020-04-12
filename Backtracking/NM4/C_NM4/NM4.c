#include <stdio.h>

#define MAX 8 + 1

int n, m;
int num_list[MAX];

void combination_with_repetition(int cnt, int cur)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", num_list[i]);
		}
		printf("\n");
		return;
	}

	for (int i = cur; i <= n; i++)
	{
		num_list[cnt] = i;
		combination_with_repetition(cnt + 1, i);
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);

	combination_with_repetition(0, 1);

	return 0;
}
