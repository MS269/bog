#include <iostream>
#include <vector>

#define MOD 15746

using namespace std;

int n;
vector<int> d;

void tiles()
{
	d.push_back(0);
	d.push_back(1);
	d.push_back(2);

	for (int i = 3; i <= n; i++)
		d.push_back((d[i - 1] + d[i - 2]) % MOD);
}

int main()
{
	cin >> n;

	tiles();

	cout << d[n] << "\n";

	return 0;
}
