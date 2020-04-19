#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX 20
#define min(a, b) (((a) < (b)) ? (a) : (b))

int n;
int s[MAX][MAX];
int team[MAX];
int min_diff = INT_MAX;

void get_min_diff(int cnt, int cur)
{
	if (cnt == n / 2)
	{
		int start_tot = 0, link_tot = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (team[i] && team[j])
					start_tot += s[i][j] + s[j][i];
				else if (!team[i] && !team[j])
					link_tot += s[i][j] + s[j][i];
			}
		}

		min_diff = min(min_diff, abs(start_tot - link_tot));

		return;
	}

	for (int i = cur; i < n; i++)
	{
		if (!team[i])
		{
			team[i] = 1;
			get_min_diff(cnt + 1, i);
			team[i] = 0;
		}
	}
}

int main()
{
	int team[MAX];

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &s[i][j]);

	get_min_diff(0, 1);

	printf("%d\n", min_diff);

	return 0;
}
