#include <stdio.h>

#define MAX 8 + 1

int n, m;
int num_list[MAX];
int check_list[MAX];

void combination(int cnt, int cur)
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
		if (!check_list[i])
		{
			num_list[cnt] = i;
			check_list[i] = 1;
			combination(cnt + 1, i + 1);
			check_list[i] = 0;
		}
	}
}

int main()
{
	scanf_s("%d %d", &n, &m);

	combination(0, 1);

	return 0;
}
