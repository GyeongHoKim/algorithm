import java.io.*;
import java.util.*;

public class Main17404 {
    public static int n;
    public static int[][] cost = new int[1001][3];
    public static int[][] cache = new int[1001][3];

    public static int dfs(int house, int idx) {
        if (house <= 1)
            return cache[1][idx];
        if (house == n) {
            for (int i = 0; i < 3; ++i) {
                cache[1][i] = cost[1][i];
                if (i == idx)
                    cache[1][i] = 987654321;
            }
        }
        if (cache[house][idx] != 987654321)
            return cache[house][idx];
        for (int i = 0; i < 3; ++i) {
            if (i == idx)
                continue;
            cache[house][idx] = Math.min(cache[house][idx], cost[house][idx] + dfs(house - 1, i));
        }
        return cache[house][idx];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; ++i) {
            String[] tmp = br.readLine().split(" ");
            for (int j = 0; j < 3; ++j)
                cost[i][j] = Integer.parseInt(tmp[j]);
        }

        int ans = 987654321;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n + 1; ++j)
                Arrays.fill(cache[j], 987654321);
            ans = Math.min(ans, dfs(n, i));
        }
        System.out.println(ans);
    }
}
