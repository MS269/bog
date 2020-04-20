#include <stdio.h>
#include <stdlib.h>

long long fibonacci(int n)
{
	long long rslt;
	long long* memoization = (long long*)malloc((n + 1) * sizeof(long long));

	memoization[0] = 0;
	memoization[1] = 1;

	for (int i = 2; i <= n; i++)
		memoization[i] = memoization[i - 1] + memoization[i - 2];

	rslt = memoization[n];
	free(memoization);

	return rslt;
}

int main()
{
	int n;

	scanf_s("%d", &n);

	printf("%lld\n", fibonacci(n));

	return 0;
}
