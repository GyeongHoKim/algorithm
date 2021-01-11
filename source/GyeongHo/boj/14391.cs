using System;
using System.Linq;

namespace paperNS
{
	class paperClass
	{
		static void countMax(int N, int M, ref int MAX, ref int[,] paper)
		{
			int sum = 0;
			for(int bitMask = 0; bitMask < 0xFFFF; ++bitMask) {
				//horizonal traverse
				for(int i = 0; i < N; ++i) {
					int tmp = 1;
					for(int j = M - 1; j > 0; --j) {
						if((bitMask & (1 << (i * M + j))) == 0 && (bitMask & (1 << (i * M + j - 1))) == 0) {
							sum += tmp * paper[i, j];
							tmp *= 10;
						}
					}
				}
				
				//vertical traverse
				for(int i = 0; i < N; ++i) {
					int tmp = 1;
					for(int j = M - 1; j > 0; --j) {
						if((bitMask & (1 << (i * M + j))) == 1 && (bitMask & (1 << (i * M + j - 1))) == 1) {
							sum += tmp * paper[i, j];
							tmp *= 10;
						}
					}
				}
				if(MAX < sum) MAX = sum;
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
