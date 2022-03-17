import java.util.*;

public class Main9252 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1, s2;
        s1 = sc.next();
        s2 = sc.next();
        sc.close();

        int n1 = s1.length();
        int n2 = s2.length();
        int[][] dp = new int[n1 + 1][n2 + 1];
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
        System.out.println(dp[n1][n2]);
        if (dp[n1][n2] == 0)
            return;
        
        StringBuilder sb = new StringBuilder();
        int i = n1, j = n2;
        while (i >= 1 && j >= 1) {
            if (dp[i][j] == dp[i - 1][j])
                --i;
            else if (dp[i][j] == dp[i][j - 1])
                --j;
            else {
                sb.append(s1.charAt(i - 1));
                --i;
                --j;
            }
        }
        System.out.println(sb.reverse());
    }
}
