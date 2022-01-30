package source.GyeongHo.boj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main11728 {
    public static int n, m;
    public static int[] a = new int[1000000];
    public static int[] b = new int[1000000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String[] tmp = br.readLine().split(" ");
        String[] arrA = br.readLine().split(" ");
        String[] arrB = br.readLine().split(" ");

        int aIdx = 0, bIdx = 0;
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        for (int i = 0; i < n; ++i)
            a[i] = Integer.parseInt(arrA[i]);
        for (int i = 0; i < m; ++i)
            b[i] = Integer.parseInt(arrB[i]);
        
        while (aIdx < n && bIdx < m) {
            if (a[aIdx] < b[bIdx])
                bw.write(String.valueOf(a[aIdx++]) + " ");
            else
                bw.write(String.valueOf(b[bIdx++]) + " ");
        }
        while (aIdx < n)
            bw.write(String.valueOf(a[aIdx++]) + " ");
        while (bIdx < m)
            bw.write(String.valueOf(b[bIdx++]) + " ");
        bw.flush();
        bw.close();
    }
}
