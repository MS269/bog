#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 300

int stairs[MAX + 1];
int dp[MAX + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stairs[i];
	}
	dp[1] = stairs[1];
	dp[2] = max(stairs[2], stairs[1] + stairs[2]);
	dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	cout << dp[n] << '\n';

	return 0;
}
