#include <iostream>
#include <algorithm>

#define MAX 1000

using namespace std;

struct Cost
{
	int R;
	int G;
	int B;
} cost[MAX + 1];

int main()
{
	int n;
	Cost temp;
	int min_cost;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp.R >> temp.G >> temp.B;

		cost[i].R = temp.R + min(cost[i - 1].G, cost[i - 1].B);
		cost[i].G = temp.G + min(cost[i - 1].R, cost[i - 1].B);
		cost[i].B = temp.B + min(cost[i - 1].R, cost[i - 1].G);
	}

	min_cost = min(min(cost[n].R, cost[n].G), cost[n].B);

	cout << min_cost << "\n";

	return 0;
}
