import java.util.*;
import java.io.*;

public class Main2467 {
    public static int n, min_val = Integer.MAX_VALUE;
    public static int[] liquid = new int[100000];
    public static int[] ans = new int[2];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            liquid[i] = Integer.parseInt(st.nextToken());
        
        for (int i = 0; i < n; ++i) {
            int start = i + 1, end = n - 1;
            while (start <= end) {
                int middle = (start + end) / 2;
                int sum = liquid[i] + liquid[middle];
                if (Math.abs(sum) < min_val) {
                    ans[0] = liquid[i];
                    ans[1] = liquid[middle];
                    min_val = Math.abs(sum);
                }

                if (sum <= 0)
                    start = middle + 1;
                else
                    end = middle - 1;
            }
        }

        System.out.print(String.valueOf(ans[0]) + " " + String.valueOf(ans[1]));
    }
}
