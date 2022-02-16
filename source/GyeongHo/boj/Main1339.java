import java.io.IOException;
import java.util.*;

public class Main1339 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];
        int[] alpha = new int[26];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.next();
        }
        sc.close();

        for (int i = 0; i < n; ++i) {
            int tmp = 1;
            for (int j = 0; j < arr[i].length() - 1; ++j) {
                tmp *= 10;
            }
            for (int j = 0; j < arr[i].length(); ++j) {
                alpha[(int)arr[i].charAt(j) - 65] += tmp;
                tmp /= 10;
            }
        }

        Arrays.sort(alpha);
        int weight = 9;
        int sum = 0;
        for (int i = 25; i >= 0; --i) {
            if (alpha[i] == 0)
                break;
            sum += alpha[i] * weight--;
        }
        System.out.print(sum);
    }
}