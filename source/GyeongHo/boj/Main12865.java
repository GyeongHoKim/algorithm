import java.io.*;
import java.util.*;

public class Main12865 {
    public static void main(String[] args) throws IOException {
        int n, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[] value = new int[n + 1];
        int[] weight = new int[n + 1];
        int[][] dp = new int[n + 1][k + 1];

        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            weight[i] = Integer.parseInt(st.nextToken());
            value[i] = Integer.parseInt(st.nextToken());
        }

        int max_val = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (weight[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
                max_val = max_val < dp[i][j] ? dp[i][j] : max_val;
            }
        }
        System.out.println(max_val);
    }
}
