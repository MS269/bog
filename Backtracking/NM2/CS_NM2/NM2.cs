using System;
using System.Collections.Generic;

namespace CS_NM1
{
    static class Constants
    {
        public const int Max = 8 + 1;
    }

    class NM2
    {
        static int n, m;
        static List<int> numList = new List<int>();
        static bool[] checkList = new bool[Constants.Max];

        static void Combination(int cnt, int cur)
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
                if (!checkList[i])
                {
                    numList.Add(i);
                    checkList[i] = true;
                    Combination(cnt + 1, i + 1);
                    numList.RemoveAt(cnt);
                    checkList[i] = false;
                }
            }
        }

        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            n = Convert.ToInt32(input[0]);
            m = Convert.ToInt32(input[1]);

            Combination(0, 1);
        }
    }
}
