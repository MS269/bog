using System;
using System.Collections.Generic;

namespace CSPadovanSequence
{
    static class Constants
    {
        public const int Max = 100;
    }

    class PadovanSequence
    {
        static List<long> padovanSequence = new List<long>(Constants.Max + 1);

        static void getPadovanSequence()
        {
            padovanSequence.Add(0);
            padovanSequence.Add(1);
            padovanSequence.Add(1);
            padovanSequence.Add(1);

            for (int i = 4; i <= Constants.Max; i++)
                padovanSequence.Add(padovanSequence[i - 2] + padovanSequence[i - 3]);
        }

        static void Main(string[] args)
        {
            getPadovanSequence();

            int t = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine(padovanSequence[n]);
            }
        }
    }
}
