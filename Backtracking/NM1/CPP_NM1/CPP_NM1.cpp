#include <iostream>
#include <vector>

#define MAX 8 + 1

using namespace std;

int n, m;
vector<int> num_list;
vector<bool> check_list(MAX);

void permutation(int cnt)
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
        if (!check_list[i])
        {
            num_list.push_back(i);
            check_list[i] = true;
            permutation(cnt + 1);
            num_list.pop_back();
            check_list[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    permutation(0);

    return 0;
}
