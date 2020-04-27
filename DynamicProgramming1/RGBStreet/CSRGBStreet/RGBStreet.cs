using System;

namespace CSRGBStreet
{
    static class Constants
    {
        public const int Max = 1000;
    }

    public struct Cost
    {
        public int R;
        public int G;
        public int B;
    }

    class RGBStreet
    {
        static Cost[] cost = new Cost[Constants.Max + 1];

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 1; i <= n; i++)
            {
                Cost temp;
                string[] s = Console.ReadLine().Split();
                temp.R = Convert.ToInt32(s[0]);
                temp.G = Convert.ToInt32(s[1]);
                temp.B = Convert.ToInt32(s[2]);

                cost[i].R = temp.R + Math.Min(cost[i - 1].G, cost[i - 1].B);
                cost[i].G = temp.G + Math.Min(cost[i - 1].R, cost[i - 1].B);
                cost[i].B = temp.B + Math.Min(cost[i - 1].R, cost[i - 1].G);
            }

            int minCost = Math.Min(Math.Min(cost[n].R, cost[n].G), cost[n].B);

            Console.WriteLine(minCost);
        }
    }
}
