class Solution {
    public int[] dp = new int[15];
    public int solution(int n) {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        if (n < 3)
            return dp[n];
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j <= (i - 1) / 2; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
            dp[i] += dp[i];
            if (i % 2 == 1)
                dp[i] -= dp[(i - 1) / 2] * dp[(i - 1) / 2];
        }
        return dp[n];

    }
}