import java.io.*;
import java.util.*;

public class Main12852 {
    public static int[] cache = new int[1000001];
    public static int n;
    public static StringBuilder sb = new StringBuilder();

    public static void pathFind(int idx) {
        if (idx == 0)
            return;
        sb.append(idx + " ");
        
        if (idx % 3 == 0 && cache[idx] == cache[idx / 3] + 1)
            pathFind(idx / 3);
        else if (idx % 2 == 0 && cache[idx] == cache[idx / 2] + 1)
            pathFind(idx / 2);
        else if (idx - 1 >= 0 && cache[idx] == cache[idx - 1] + 1)
            pathFind(idx - 1);
    }

    public static int dfs(int idx) {
        if (cache[idx] != Integer.MAX_VALUE)
            return cache[idx];
        if (idx == 1) {
            return cache[1] = 0;
        }
        int n1 = Integer.MAX_VALUE, n2 = Integer.MAX_VALUE, n3 = Integer.MAX_VALUE;
        if (idx > 2 && idx % 3 == 0)
            n1 = dfs(idx / 3) + 1;
        if (idx % 2 == 0)
            n2 = dfs(idx / 2) + 1;
        n3 = dfs(idx - 1) + 1;
        return cache[idx] = Math.min(Math.min(n1, n2), n3);
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.close();
        Arrays.fill(cache, Integer.MAX_VALUE);

        System.out.println(dfs(n));
        pathFind(n);
        System.out.println(sb.toString());
    }
}