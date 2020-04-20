#include <iostream>

using namespace std;

long long fibonacci(int n)
{
    long long rslt;
    long long* memoization = new long long[n + 1];

    memoization[0] = 0;
    memoization[1] = 1;

    for (int i = 2; i <= n; i++)
        memoization[i] = memoization[i - 1] + memoization[i - 2];

    rslt = memoization[n];
    delete[] memoization;

    return rslt;
}

int main()
{
    int n;

    cin >> n;

    cout << fibonacci(n) << "\n";

    return 0;
}
