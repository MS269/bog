#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 20

using namespace std;

int n;
int s[MAX][MAX];
vector<int> start, link;
int min_diff = INT_MAX;

void get_min_diff(int cnt)
{
	if (cnt == n)
	{
		if (start.size() == n / 2 && link.size() == n / 2)
		{
			int start_tot = 0, link_tot = 0;

			for (int i = 0; i < n / 2; i++)
			{
				for (int j = i + 1; j < n / 2; j++)
				{
					start_tot += s[start[i]][start[j]] + s[start[j]][start[i]];
					link_tot += s[link[i]][link[j]] + s[link[j]][link[i]];
				}
			}

			min_diff = min(min_diff, abs(start_tot - link_tot));
		}

		return;
	}

	start.push_back(cnt);
	get_min_diff(cnt + 1);
	start.pop_back();

	link.push_back(cnt);
	get_min_diff(cnt + 1);
	link.pop_back();
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	get_min_diff(0);

	cout << min_diff << "\n";

	return 0;
}
