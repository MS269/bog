#include <stdio.h>

#define MAX 41

int memo_0[MAX] = {1, 0};
int memo_1[MAX] = {0, 1};

void fibonacci_function()
{
	for (int i = 2; i < MAX; i++)
	{
		memo_0[i] = memo_0[i - 1] + memo_0[i - 2];
		memo_1[i] = memo_1[i - 1] + memo_1[i - 2];
	}
}

int main()
{
	int t, n;

	fibonacci_function();

	scanf_s("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		printf("%d %d\n", memo_0[n], memo_1[n]);
	}

	return 0;
}
