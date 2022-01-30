package source.GyeongHo.boj;

import java.io.*;

public class Padovan9461 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t;
        long[] d = new long[101];
        d[1] = 1;
        d[2] = 1;
        d[3] = 1;
        for (int i = 4; i < 101; ++i)
            d[i] = d[i - 2] + d[i - 3];
        t = Integer.parseInt(bf.readLine());
        while (t-- > 0) {
            int idx = Integer.parseInt(bf.readLine());
            System.out.println(d[idx]);
        }
    }
}