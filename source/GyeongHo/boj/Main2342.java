import java.util.*;
import java.io.*;

public class Main2342 {
    static int[] positions;
    static int[][][] dp;

    public static int costWhen(int start, int end) {
        if (start == 0)
            return 2;
        else if (start - end == 2 || start - end == -2)
            return 4;
        else if (start == end)
            return 1;
        else
            return 3;
    }

    public static int dfs(int step, int left, int right) {
        if (step >= positions.length)
            return 0;
        if (dp[step][left][right] != 0)
            return dp[step][left][right];
        int leftCost = dfs(step + 1, positions[step], right) + costWhen(left, positions[step]);
        int rightCost = dfs(step + 1, left, positions[step]) + costWhen(right, positions[step]);
        return dp[step][left][right] = Math.min(leftCost, rightCost);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        positions = new int[tmp.length - 1];
        for (int i = 0; i < tmp.length - 1; ++i)
            positions[i] = Integer.parseInt(tmp[i]);
        
        dp = new int[positions.length][5][5];
        System.out.println(dfs(0, 0, 0));
    }
}