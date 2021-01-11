using System;
using System.Linq;

namespace paperNS
{
	class paperClass
	{
		static void countMax(int N, int M, ref int MAX, ref int[,] paper)
		{
			int sum = 0;
			for(int bitMask = 0; bitMask < (1 << N * M); ++bitMask) {
				//horizonal traverse
				for(int i = 0; i < N; ++i) {
					int tmp = 1;
					for(int j = M - 1; j >= 0; --j) {
						int shift = 1 << (i * M + j);
						if((~bitMask & shift) == 1) {
							sum += tmp * paper[i, j];
							tmp *= 10;
						}
						else tmp = 1;
					}
				}
				
				//vertical traverse
				for(int i = 0; i < M; ++i) {
					int tmp = 1;
					for(int j = N - 1; j > 0; --j) {
						int shift = 1 << (j * M + i);
						if((bitMask & shift) == 1) {
							sum += tmp * paper[i, j];
							tmp *= 10;
						}
						else tmp = 1;
					}
				}
				if(MAX < sum) MAX = sum;
				sum = 0;
			}
		}

		static int Main()
		{
			int N, M, MAX = 0;
			int[,] paper = new int[4, 4];
			var temp = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
			N = temp[0]; M = temp[1];
			for(int i = 0; i < N; ++i) {
				string temp2 = Console.ReadLine();
				for(int j = 0; j < M; ++j)
					paper[i, j] = temp2[j];
			}

			countMax(N, M, ref MAX, ref paper);
			Console.WriteLine(MAX);

			return 0;
		}
	}
}
