import java.util.*;
import java.io.*;

public class Main10830 {
    public static int[][] a = new int[5][5];
    public static int n;
    public static long b;
    public static final int div = 1000;

    public static int[][] multiply(int[][] m1, int[][] m2) {
        int[][] ret = new int[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ret[i][j] += ((m1[i][k] % div) * (m2[k][j] % div)) % div;
                    ret[i][j] %= div;
                }
            }
        }
        
        return ret;
    }

    public static int[][] powerA(int[][] matrix, long exp) {
        if (exp == 1L) {
            return matrix;
        }

        int[][] ret = powerA(matrix, exp / 2);
        
        ret = multiply(ret, ret);
        if (exp % 2 == 1L)
            ret = multiply(ret, a);

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        b = Long.parseLong(tmp[1]);
    
        for (int i = 0; i < n; ++i) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < n; ++j) {
                a[i][j] = Integer.parseInt(tmp[j]) % div;
            }
        }

        int[][] ans = powerA(a, b);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sb.append(ans[i][j] + " ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}