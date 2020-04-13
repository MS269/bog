#include <iostream>

#define MAX 14

using namespace std;

int n, ans;
bool height[MAX], down_top_diagonal[2 * MAX - 1], top_down_diagonal[2 * MAX - 1];

void n_queen(int i)
{
	if (i == n)
	{
		ans++;
		return;
	}

	for (int j = 0; j < n; j++)
	{
		if (height[j] || down_top_diagonal[i + j] || top_down_diagonal[i - j + n - 1])
			continue;

		height[j] = down_top_diagonal[i + j] = top_down_diagonal[i - j + n - 1] = true;
		n_queen(i + 1);
		height[j] = down_top_diagonal[i + j] = top_down_diagonal[i - j + n - 1] = false;
	}
}

int main()
{
	cin >> n;

	n_queen(0);

	cout << ans << "\n";

	return 0;
}
