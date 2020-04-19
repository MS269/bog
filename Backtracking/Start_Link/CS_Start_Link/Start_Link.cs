using System;
using System.Collections.Generic;

namespace CS_Start_Link
{
    static class Constants
    {
        public const int Max = 20;
    }

    class Start_Link
    {
        static int n;
        static int[,] s = new int[Constants.Max, Constants.Max];
        static List<int> start = new List<int>();
        static List<int> link = new List<int>();
        static int minDiff = int.MaxValue;

        static void GetMinDiff(int cnt)
        {
            if (cnt == n)
            {
                if (start.Count == n / 2 && link.Count == n / 2)
                {
                    int startTot = 0, linkTot = 0;

                    for (int i = 0; i < n / 2; i++)
                    {
                        for (int j = i + 1; j < n / 2; j++)
                        {
                            startTot += s[start[i], start[j]] + s[start[j], start[i]];
                            linkTot += s[link[i], link[j]] + s[link[j], link[i]];
                        }
                    }

                    minDiff = Math.Min(minDiff, Math.Abs(startTot - linkTot));
                }

                return;
            }

            start.Add(cnt);
            GetMinDiff(cnt + 1);
            start.RemoveAt(start.FindLastIndex(idx => idx >= 0));
            
            link.Add(cnt);
            GetMinDiff(cnt + 1);
            link.RemoveAt(link.FindLastIndex(idx => idx >= 0));
        }

        static void Main(string[] args)
        {
            n = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                string[] l = Console.ReadLine().Split();
                for (int j = 0; j < n; j++)
                    s[i, j] = Convert.ToInt32(l[j]);
            }

            GetMinDiff(0);

            Console.WriteLine(minDiff);
        }
    }
}
