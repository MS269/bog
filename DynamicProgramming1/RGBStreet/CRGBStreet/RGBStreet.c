#include <stdio.h>

#define MAX 1000
#define min(a, b) ((a) < (b) ? (a) : (b))

struct Cost
{
	int R;
	int G;
	int B;
} cost[MAX + 1];

int main()
{
	int n;
	struct Cost temp;
	int min_cost;

	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d %d %d", &temp.R, &temp.G, &temp.B);

		cost[i].R = temp.R + min(cost[i - 1].G, cost[i - 1].B);
		cost[i].G = temp.G + min(cost[i - 1].R, cost[i - 1].B);
		cost[i].B = temp.B + min(cost[i - 1].R, cost[i - 1].G);
	}

	min_cost = min(min(cost[n].R, cost[n].G), cost[n].B);

	printf("%d\n", min_cost);

	return 0;
}
