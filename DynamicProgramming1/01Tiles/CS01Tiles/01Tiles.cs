using System;
using System.Collections.Generic;

namespace CS01Tiles
{
    static class Constants
    {
        public const int Mod = 15746;
    }

    class Tiles
    {
        static int n;
        static List<int> d = new List<int>();

        static void GetTiles()
        {
            d.Add(0);
            d.Add(1);
            d.Add(2);

            for (int i = 3; i <= n; i++)
                d.Add((d[i - 1] + d[i - 2]) % Constants.Mod);
        }

        static void Main(string[] args)
        {
            n = Convert.ToInt32(Console.ReadLine());

            GetTiles();

            Console.WriteLine(d[n]);
        }
    }
}
