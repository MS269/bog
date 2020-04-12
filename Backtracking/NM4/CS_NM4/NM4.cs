using System;
using System.Collections.Generic;

namespace CS_NM4
{
    class NM4
    {
        static int n, m;
        static List<int> numList = new List<int>();

        static void CombinationWithRepetition(int cnt, int cur)
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

            for (int i = cur; i <= n; i++)
            {
                numList.Add(i);
                CombinationWithRepetition(cnt + 1, i);
                numList.RemoveAt(cnt);
            }
        }

        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            n = Convert.ToInt32(input[0]);
            m = Convert.ToInt32(input[1]);

            CombinationWithRepetition(0, 1);
        }
    }
}
