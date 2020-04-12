using System;
using System.Collections.Generic;

namespace CS_NM3
{
    class Program
    {
        static int n, m;
        static List<int> numList = new List<int>();

        static void PermutationWithRepetition(int cnt)
        {
            if (cnt == m)
            {
                foreach (var num in numList)
                {
                    Console.Write("{0} ", num);
                }
                Console.WriteLine();
                return;
            }

            for (int i = 1; i <= n; i++)
            {
                numList.Add(i);
                PermutationWithRepetition(cnt + 1);
                numList.RemoveAt(cnt);
            }
        }

        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            n = Convert.ToInt32(input[0]);
            m = Convert.ToInt32(input[1]);

            PermutationWithRepetition(0);
        }
    }
}
