using System;

namespace CS_Fibonacci
{
    class Fibonacci
    {
        static long Fib(int n)
        {
            long[] memoization = new long[n + 1];

            memoization[0] = 0;
            memoization[1] = 1;

            for (int i = 2; i <= n; i++)
                memoization[i] = memoization[i - 1] + memoization[i - 2];

            return memoization[n];
        }

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine(Fib(n));
        }
    }
}
