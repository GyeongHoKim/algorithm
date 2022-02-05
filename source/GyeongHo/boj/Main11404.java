package source.GyeongHo.boj;

import java.io.*;
import java.util.Arrays;

public class Main11404 {
    public static int[][] dist = new int[101][101];
    
    public static void main(String[] args) throws IOException {
        int n, m;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        for (int i = 0; i < 101; ++i) {
            Arrays.fill(dist[i], 987654321);
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            String[] tmp = br.readLine().split(" ");
            int s = Integer.parseInt(tmp[0]), e = Integer.parseInt(tmp[1]), c = Integer.parseInt(tmp[2]);
            dist[s][e] = Math.min(c, dist[s][e]);
        }
        br.close();

        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] > 10000000)
                    dist[i][j] = 0;
                sb.append(dist[i][j]);
                sb.append(' ');
            }
            sb.append('\n');
        }
        System.out.print(sb.toString());
    }
}
