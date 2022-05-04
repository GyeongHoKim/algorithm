import java.util.*;
import java.io.*;

/**
 * 생각해보자. 주어지는 것은 앱 별 바이트 크기. m만큼의 바이트를 마련하기 위해서
 * 몇 개의 앱을 없애야 하는데 없애는 데에 드는 비용이 c만큼이라고 생각해도 좋다.
 * 비용을 최소로 몇 개의 앱을 골라야 하는데
 * 비용은 최소로 크기는 최대로. 서로 반대가 되는 조건으로 가야 함. DFS할 수 있나?
 * 
 * 는 이제보니 01 knapsack problem이다. dp문제. 메모리는 최대한 크게, 비용은 최대한 작게. 즉 2개 반대로.
 * 앱 개수랑 비용을 dp배열로 잡고 내용은 확보되는 메모리 크기로.
 * 최소로 가져가야 하는 피처를 row 피처로 줘야 하고 최대로 가져가는 값을 내용으로 줘야 풀기 쉬움.
 */

public class Main7579 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n, m, totalCost = 0;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[] mem = new int[n + 1];
        int[] cost = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i)
            mem[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i) {
            cost[i] = Integer.parseInt(st.nextToken());
            totalCost += cost[i];
        }
        br.close();
        

        int[][] dp = new int[n + 1][totalCost + 1];
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < totalCost + 1; ++j) {
                if (cost[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], mem[i] + dp[i - 1][j - cost[i]]);
            }
        }

        int min_cost = -1;
        for (int i = 0; i < totalCost + 1; ++i) {
            if (min_cost != -1)
                break;
            for (int j = 1; j < n + 1; ++j)
                if (dp[j][i] >= m)
                    min_cost = i;
        }
                
        
        System.out.println(min_cost);
    }
}
