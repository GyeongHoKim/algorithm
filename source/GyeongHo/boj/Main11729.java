import java.util.*;
import java.io.*;

public class Main11729 {
    static int k;
    static StringBuilder sb = new StringBuilder();
    static int[] dp = new int[21];

    static int cnt(int n) {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] * 2 + 1;
        return dp[n];
    }

    static void hanoi(int n, int start, int end) {
        if (n == 1) {
            sb.append(start);
            sb.append(' ');
            sb.append(end);
            sb.append('\n');
            return;
        }
        hanoi(n - 1, start, 6 - start - end);
        hanoi(1, start, end);
        hanoi(n - 1, 6 - start - end, end);
        return;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();

        System.out.println(cnt(k));
        hanoi(k, 1, 3);
        System.out.print(sb.toString());
    }
}
