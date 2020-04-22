#include <stdio.h>

#define MAX 1000000
#define MOD 15746

int n;
int d[MAX + 1] = {0, 1, 2};

void tiles()
{
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2]) % MOD;
}

int main()
{
	scanf_s("%d", &n);

	tiles();

	printf("%d\n", d[n]);

	return 0;
}
