#include <stdio.h>

#define MAX 7 + 1

int n, m;
int num_list[MAX];

void permutation_with_repetition(int cnt)
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

	for (int i = 1; i <= n; i++)
	{
		num_list[cnt] = i;
		permutation_with_repetition(cnt + 1);
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);

	permutation_with_repetition(0);

	return 0;
}
