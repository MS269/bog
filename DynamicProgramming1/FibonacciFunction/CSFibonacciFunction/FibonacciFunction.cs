using System;
using System.Collections.Generic;

namespace CSFibonacciFunction
{
    static class Constants
    {
        public const int Max = 41;
    }

    class FibonacciFunction
    {
        static List<int> memo0 = new List<int>(Constants.Max);
        static List<int> memo1 = new List<int>(Constants.Max);

        static void FibFunc()
        {
            memo0.Add(1);
            memo1.Add(0);
            memo0.Add(0);
            memo1.Add(1);

            for (int i = 2; i < Constants.Max; i++)
            {
                memo0.Add(memo0[i - 1] + memo0[i - 2]);
                memo1.Add(memo1[i - 1] + memo1[i - 2]);
            }
        }

        static void Main(string[] args)
        {
            FibFunc();

            int t = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("{0} {1}", memo0[n], memo1[n]);
            }
        }
    }
}
