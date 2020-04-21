#include <iostream>
#include <vector>

#define MAX 41

using namespace std;

vector<int> memo_0(MAX);
vector<int> memo_1(MAX);

void fibonacci_function()
{
	memo_0.push_back(1);
	memo_1.push_back(0);
	memo_0.push_back(0);
	memo_1.push_back(1);

	for (int i = 2; i < MAX; i++)
	{
		memo_0.push_back(memo_0[i - 1] + memo_0[i - 2]);
		memo_1.push_back(memo_1[i - 1] + memo_1[i - 2]);
	}
}

int main()
{
	int t, n;

	fibonacci_function();

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << memo_0[n] << " " << memo_1[n] << "\n";
	}

	return 0;
}
