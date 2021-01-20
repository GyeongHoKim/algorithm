using System;

namespace tile
{
	class tiling
	{
		static int[] cache = new int[1001];
		static int dfs(int n)
		{
			if(cache[n] != -1) return cache[n];
			else return cache[n] = (dfs(n - 1) + 2 * dfs(n - 2)) % 10007;
		}
		
		static void Main()
		{
			int n;
			n = int.Parse(Console.ReadLine());
			for(int i = 0; i < 1001; ++i)
				cache[i] = -1;
			cache[1] = 1;
			cache[2] = 3;

			Console.Write(dfs(n));
		}
	}
}
