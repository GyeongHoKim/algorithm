import java.util.*;
import java.io.*;

public class Main1809 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            arr[i] = Integer.parseInt(st.nextToken());
        
        int first = 0, second = 0, min_length = n + 1, total = arr[0];
        while (first < n && second < n) {
            if (min_length == 1)
                break;
            else if (total >= s) {
                min_length = Math.min(min_length, second - first + 1);
                total -= arr[first++];
            }
            else if (second == n - 1)
                break;
            else {
                total += arr[++second];
            }
        }
        if (min_length == n + 1)
            min_length = 0;
        System.out.println(min_length);
    }
}
