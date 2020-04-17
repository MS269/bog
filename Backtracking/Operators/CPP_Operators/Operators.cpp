#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> numbers;
int operators[4];
int max_num = -1e9;
int min_num = 1e9;

void insert_operators(int num, int add, int sub, int mul, int div, int cnt)
{
	if (cnt == n)
	{
		max_num = max(max_num, num);
		min_num = min(min_num, num);
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	for (int i = 0; i < 4; i++)
		cin >> operators[i];

	insert_operators(numbers[0], operators[0], operators[1], operators[2], operators[3], 1);

	cout << max_num << "\n";
	cout << min_num << "\n";

	return 0;
}
