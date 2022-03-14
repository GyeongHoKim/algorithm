import java.io.*;
import java.util.*;

public class Main2473 {
    public static int n;
    public static long[] liquid = new long[5000];
    public static long[] answer = new long[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            liquid[i] = Long.parseLong(st.nextToken());
        
        Arrays.sort(liquid, 0, n);
        long max_val = Long.MAX_VALUE;

        for (int i = 0; i < n - 1; ++i) {
            int start = i + 1;
            int end = n - 1;
            int center = end - 1;

            while (center < end) {
                center = end - 1;
                while (start <= center) {
                    int mid = (start + center) / 2;
                    long sum = liquid[i] + liquid[mid] + liquid[end];

                    if (Math.abs(sum) < max_val) {
                        answer[0] = liquid[i];
                        answer[1] = liquid[mid];
                        answer[2] = liquid[end];
                        max_val = Math.abs(sum);
                    }

                    if (sum < 0)
                        start = mid + 1;
                    else
                        center = mid - 1;
                }
                --end;
            }
        }
        System.out.println(answer[0] + " " + answer[1] + " " + answer[2]);
    }
}
