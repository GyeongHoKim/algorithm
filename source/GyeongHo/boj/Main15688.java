package source.GyeongHo.boj;

import java.io.*;

public class Main15688 {
    public static int[] cache = new int[2000001];
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; ++i) {
            cache[Integer.parseInt(br.readLine()) + 1000000]++;
        }

        int idx = 0, cnt = 0;
        while (cnt <= n && idx < 2000001) {
            if (cache[idx] > 0) {
                for (int i = 0; i < cache[idx]; ++i) {
                    sb.append(idx - 1000000);
                    sb.append('\n');
                }
                ++cnt;
            }
            ++idx;
        }
        System.out.print(sb);
    }
}