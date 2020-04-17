using System;
using System.Collections.Generic;

namespace CS_Operators
{
    class Operators
    {
        static int n;
        static List<int> numbers = new List<int>();
        static int[] operators = new int[4];
        static int maxNum = -1000000000;
        static int minNum = 1000000000;

		static void InsertOperators(int num, int add, int sub, int mul, int div, int cnt)
		{
			if (cnt == n)
			{
				maxNum = Math.Max(maxNum, num);
				minNum = Math.Min(minNum, num);
				return;
			}

			if (add != 0)
				InsertOperators(num + numbers[cnt], add - 1, sub, mul, div, cnt + 1);
			if (sub != 0)
				InsertOperators(num - numbers[cnt], add, sub - 1, mul, div, cnt + 1);
			if (mul != 0)
				InsertOperators(num * numbers[cnt], add, sub, mul - 1, div, cnt + 1);
			if (div != 0)
				InsertOperators(num / numbers[cnt], add, sub, mul, div - 1, cnt + 1);
		}

		static void Main(string[] args)
        {
			n = Convert.ToInt32(Console.ReadLine());

			string[] temp = Console.ReadLine().Split();
			for (int i = 0; i < n; i++)
				numbers.Add(Convert.ToInt32(temp[i]));

			temp = Console.ReadLine().Split();
			for (int i = 0; i < 4; i++)
				operators[i] = Convert.ToInt32(temp[i]);

			InsertOperators(numbers[0], operators[0], operators[1], operators[2], operators[3], 1);

			Console.WriteLine(maxNum);
			Console.WriteLine(minNum);
		}
    }
}
