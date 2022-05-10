import java.util.*;
import java.io.*;

public class Main10942 {

    static int[][] dp = new int[2001][2001];
    static int[] numbers;
    
    static int isPalindrom(int s, int e) {
        if (s >= e)
            return dp[s][e] = 1;
        else if (dp[s][e] != -1)
            return dp[s][e];
        else if (numbers[s] == numbers[e])
            return dp[s][e] = isPalindrom(s + 1, e - 1);
        return dp[s][e] = 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        for (int i = 0; i <= 2000; ++i)
            Arrays.fill(dp[i], -1);
        int n = Integer.parseInt(br.readLine());
        numbers = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int m = Integer.parseInt(br.readLine());
        while(m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
            if (isPalindrom(s - 1, e - 1) == 1)
                sb.append("1\n");
            else
                sb.append("0\n");
        }
        System.out.print(sb);
    }
}
