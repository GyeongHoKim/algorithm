using System;
using System.Linq;

class TSP2
{
	static int N, MIN = 987654321;
	static bool[] visit = new bool[10];
	static int[,] W = new int[10,10];
	
	static void fullSearch(int start, int loc, int sum, int cnt)
	{
		if(cnt == N && start == loc) {
			if(sum < MIN) MIN = sum;
			return;
		}

		for(int i = 0; i < N; ++i) {
			if(visit[i] || W[loc, i] == 0) continue;
			visit[i] = true;
			sum += W[loc, i];
			if(sum < MIN) fullSearch(start, i, sum, cnt + 1);
			visit[i] = false;
			sum -= W[loc, i];
		}
	}

	static int Main()
	{
		N = Convert.ToInt32(Console.ReadLine());

		for(int i = 0; i < N; ++i) {
			var tmp = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
			for(int j = 0; j < N; ++j)
				W[i, j] = tmp[j];
		}
		
		for(int i = 0; i < N; ++i)
			fullSearch(i, i, 0, 0);

		Console.Write(MIN);
		return 0;
	}
}
