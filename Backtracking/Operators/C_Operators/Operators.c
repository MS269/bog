#include <stdio.h>

#define MAX 11

int n;
int numbers[MAX];
int operators[4];
int max = -1e9;
int min = 1e9;

void insert_operators(int num, int add, int sub, int mul, int div, int cnt)
{
	if (cnt == n)
	{
		if (max < num)
			max = num;
		if (min > num)
			min = num;
		return;
	}

	if (add)
		insert_operators(num + numbers[cnt], add - 1, sub, mul, div, cnt + 1);
	if (sub)
		insert_operators(num - numbers[cnt], add, sub - 1, mul, div, cnt + 1);
	if (mul)
		insert_operators(num * numbers[cnt], add, sub, mul - 1, div, cnt + 1);
	if (div)
		insert_operators(num / numbers[cnt], add, sub, mul, div - 1, cnt + 1);
}

int main()
{
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &numbers[i]);

	for (int i = 0; i < 4; i++)
		scanf_s("%d", &operators[i]);

	insert_operators(numbers[0], operators[0], operators[1], operators[2], operators[3], 1);

	printf("%d\n", max);
	printf("%d\n", min);

	return 0;
}
