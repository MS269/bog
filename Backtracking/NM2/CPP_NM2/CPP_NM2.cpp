#include <iostream>
#include <vector>

#define MAX 8 + 1

using namespace std;

int n, m;
vector<int> num_list;
vector<bool> check_list(MAX);

void combination(int cnt, int cur)
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
        if (!check_list[i])
        {
            num_list.push_back(i);
            check_list[i] = true;
            combination(cnt + 1, i + 1);
            num_list.pop_back();
            check_list[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    combination(0, 1);

    return 0;
}
