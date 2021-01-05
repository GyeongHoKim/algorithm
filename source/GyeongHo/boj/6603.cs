using System;
using System.Linq;

namespace Lotto
{
	class LottoClass
	{
		static int k;

		void permutation(int k, ref int[] S, int cnt, ref int[] ans, ref bool[] visit)
		{
			if(cnt == 6) {
				for(int i = 0; i < k; ++i)
					Console.Write(ans[i] + ' ');
				Consoler.WriteLine();
			}

			for(int i = 0; i < k; ++i) {
				if(visit[i]) continue;
				visit[i] = true;
				ans[i] = 
		}

		int Main()
		{
			while(1){
				var tmp = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
				k = tmp[0];
				if(k == 0) break;
				int[] S = new int[k];
				bool[] visit = new bool[k];
				S = tmp[0..];
				int[] ans = new int[k];
				
				
				permutation(k, S, 0, ans, visit);
			}

			return 0;
		}
	}
}
