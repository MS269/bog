using System;

namespace CS_N_Queen
{
    class N_Queen
    {
        static int n, ans;
        static bool[] height, downTopDiagonal, topDownDiagonal;

        static void NQueen(int i)
        {
            if (i == n)
            {
                ans++;
                return;
            }

            for (int j = 0; j < n; j++)
            {
                if (height[j] || downTopDiagonal[i + j] || topDownDiagonal[i - j + n - 1])
			        continue;

                height[j] = true;
                downTopDiagonal[i + j] = true;
                topDownDiagonal[i - j + n - 1] = true;
		        NQueen(i + 1);
		        height[j] = false;
                downTopDiagonal[i + j] = false;
                topDownDiagonal[i - j + n - 1] = false;
	
            }
        }

        static void Main(string[] args)
        {
            n = Convert.ToInt32(Console.ReadLine());

            height = new bool[n];
            downTopDiagonal = new bool[2 * n - 1];
            topDownDiagonal = new bool[2 * n - 1];

            NQueen(0);

            Console.WriteLine(ans);
        }
    }
}
