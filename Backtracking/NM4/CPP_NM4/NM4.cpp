#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> num_list;

void combination_with_repetition(int cnt, int cur)
{
    if (cnt == m)
    {
        for (int i = 0; i < num_list.size(); i++)
        {
            cout << num_list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = cur; i <= n; i++)
    {
        num_list.push_back(i);
        combination_with_repetition(cnt + 1, i);
        num_list.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    combination_with_repetition(0, 1);

    return 0;
}
