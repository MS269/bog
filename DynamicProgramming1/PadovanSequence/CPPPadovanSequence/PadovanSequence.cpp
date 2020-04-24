#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

vector<long long> padovan_sequence(MAX + 1);

void get_padovan_sequence()
{
	padovan_sequence.push_back(0);
	padovan_sequence.push_back(1);
	padovan_sequence.push_back(1);
	padovan_sequence.push_back(1);

	for (int i = 4; i <= MAX; i++)
		padovan_sequence.push_back(padovan_sequence[i - 2] + padovan_sequence[i - 3]);
}

int main()
{
	int t, n;

	get_padovan_sequence();

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << padovan_sequence[n] << "\n";
	}

	return 0;
}
