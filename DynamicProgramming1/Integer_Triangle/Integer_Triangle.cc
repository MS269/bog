#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500

int tri[MAX + 1][MAX + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
		}
	}
	int max_sum = 0;
	for (int i = 1; i <= n; i++)
	{
		max_sum = max(max_sum, tri[n][i]);
	}
	cout << max_sum;

	return 0;
}
