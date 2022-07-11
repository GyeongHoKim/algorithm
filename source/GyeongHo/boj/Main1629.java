import java.util.*;
import java.io.*;

public class Main1629 {
    static long a, b, c;

    static long power(long a, long b, long c) {
        long result = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                result = result * a % c;
            a = a * a % c;
            b = b >> 1;
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] tmp = br.readLine().split(" ");
        a = Long.parseLong(tmp[0]);
        b = Long.parseLong(tmp[1]);
        c = Long.parseLong(tmp[2]);

        System.out.println(power(a, b, c));
    }
}
