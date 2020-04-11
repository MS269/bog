using System;
using System.Collections.Generic;

namespace CS_NM1
{
    static class Constants
    {
        public const int Max = 8 + 1;
    }

    class Program
    {
        static int n, m;
        static List<int> numList = new List<int>();
        static bool[] checkList = new bool[Constants.Max];

        static void Permutation(int cnt)
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
                if (!checkList[i])
                {
                    numList.Add(i);
                    checkList[i] = true;
                    Permutation(cnt + 1);
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

            Permutation(0);
        }
    }
}
