import java.util.*;
import java.io.*;

public class Main1744 {
    static int n, mn = 0, pn = 0, zeros = 0, result = 0;
    static int[] minus = new int[50];
    static int[] plus = new int[50];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int tmp;
        for (int i = 0; i < n; ++i) {
            tmp = Integer.parseInt(br.readLine());
            if (tmp > 0)
                plus[pn++] = tmp;
            else if (tmp < 0)
                minus[mn++] = tmp;
            else
                zeros++;
        }
        Arrays.sort(minus, 0, mn);
        Arrays.sort(plus, 0, pn);
        for (int i = pn - 1; i > 0; i -= 2) {
            if (plus[i] == 1 || plus[i - 1] == 1)
                result += plus[i] + plus[i - 1];
            else
                result += plus[i] * plus[i - 1];
        }
        if (pn % 2 == 1)
            result += plus[0];
        for (int i = 0; i < mn - 1; i += 2)
            result += minus[i] * minus[i + 1];
        if (mn % 2 == 1 && zeros == 0)
            result += minus[mn - 1];

        System.out.println(result);
    }
}