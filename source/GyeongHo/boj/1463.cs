using System;

namespace evaluateMIN
{
	class makeInOne
	{
		static int[] cache = new int[1000001];

		static int dfs(int x)
		{
			if(cache[x] != -1) return cache[x];
			else if(x == 1) return cache[x] = 0;
			else if(x % 3 == 0) return cache[x] = 1 + dfs(x / 3);
			else if(x % 2 == 0) return cache[x] = 1 + dfs(x / 2);
			else return cache[x] = 1 + dfs(x - 1);
		}

		static void Main()
		{
			for(int i = 0; i < 1000001; ++i)
				cache[i] = -1;

			int x;
			x = int.Parse(Console.ReadLine());

			int MIN = dfs(x);
			for(int i = 0; i < x; ++i) {
				int tmp = i + dfs(x - i);
				if(MIN > tmp)
					MIN = tmp;
			}

			Console.Write(MIN);
		}
	}
}
