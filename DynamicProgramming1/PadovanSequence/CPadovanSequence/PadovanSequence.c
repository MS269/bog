#include <stdio.h>

#define MAX 100

long long padovan_sequence[MAX + 1] = {0, 1, 1, 1};

void get_padovan_sequence()
{
	for (int i = 4; i <= MAX; i++)
		padovan_sequence[i] = padovan_sequence[i - 2] + padovan_sequence[i - 3];
}

int main()
{
	int t, n;

	get_padovan_sequence();

	scanf_s("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		printf("%lld\n", padovan_sequence[n]);
	}

	return 0;
}
