import java.util.*;

public class Main1644 {
    public static boolean[] Eratostennis;
    public static int n, ans = 0;
    public static ArrayList<Integer> prime = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.close();

        Eratostennis = new boolean[n + 1];
        Arrays.fill(Eratostennis, true);
        Eratostennis[0] = false;
        Eratostennis[1] = false;
        for (int i = 2; i <= n; ++i)
            if (Eratostennis[i])
                for (int j = 2; j * i <= n; ++j)
                    if (Eratostennis[j * i])
                        Eratostennis[j * i] = false;
        
        for (int i = 2; i <= n; ++i)
            if (Eratostennis[i])
                prime.add(i);
        
        int start = 0, end = 0, sum = 0;
        while (start <= end) {
            if (sum >= n) {
                if (sum == n)
                    ++ans;
                sum -= prime.get(start++);
            }
            else if (end >= prime.size())
                break;
            else
                sum += prime.get(end++);
        }

        System.out.println(ans);
    }
}
