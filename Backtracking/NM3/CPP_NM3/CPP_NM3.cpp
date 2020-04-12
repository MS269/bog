#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> num_list;

void permutation_with_repetition(int cnt)
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

    for (int i = 1; i <= n; i++)
    {
        num_list.push_back(i);
        permutation_with_repetition(cnt + 1);
        num_list.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    permutation_with_repetition(0);

    return 0;
}
